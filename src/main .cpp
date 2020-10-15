#include <Arduino.h>
#include <NeoPixelBus.h>
#include "LedModule.h"
#include "webServer.h"
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <WiFiUdp.h>
#include "TimeLogic.h"
#include <LittleFS.h>

//#include "internalTimeClock.h"
//#include <effects.h> 
//accesspoint
#include <Hash.h>
using namespace std;
const char* ssid     = "WORD_CLOCK52";
const char* password = "123456789";

AsyncWebServer server(80);
//--------------------------Variablen für Effecte---------------------------------
int dummyVar = 0;     //weiss nicht mehr, wofür dei gut war?
int myEffectsMode = 2; // (256.h) modeSwitch f. User-defined Einstellungne.(0: Standart / 1: Schreibmaschine / 2: Stempel / 3: MixedMode)
int tUpDateStep1 = 4; // upDateRate Display, mögliche Werte: 1:-> 60sek, /2:-> 30sek, /3:-> 20sek, /4:-> 15sek
    //!!!----------im gui muss eine verknüpfung vorgesehen werde, damit im Mode 0 die tUpDateStep1 nur den Wert 1 annehmen kann!!
//---------------------------------------------------------------------------------
int delayInSeconds = 0;
unsigned long timeNow = 0UL;
unsigned long timeLast = 0UL;
int hours   = 10;
int minutes = 59;
int seconds = 30;
int tUpdate = 0;
int secondsupd = 0;
int refreshRate;
int flagSetAt =0;
int tFadeAway =0;
long  upDateKey = -1;
boolean displayUpdateFlag = true; //"neueMinute-Update notwendig?"  zurücksetzen
//debug-Vars------------------>
int cc = 0;
int debugTime = 1212;
//------------------Input Parameter for Webserver-------->
const char* PARAM_INPUT_1 = "HOUR";
const char* PARAM_INPUT_2 = "MINUTE";
const char* PARAM_INPUT_3 = "SECOND";
const long utcOffsetInSeconds = 3600;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
File f1;
// Define NTP Client to get time

String processor(const String& var){
  Serial.println(var);
   if(var == "MINUTE"){return String(minutes);}
             else if (var =="SECOND"){return String(seconds);  }
                    else if (var =="HOUR"){return String(hours);}
                                                    else return "uups";}

//----------------------------------BEGIN OF SETUP---------------------------> 
void setup(){
  //WIFI INIT
  Serial.begin(115200);
  delay(1000UL);
  WiFi.softAP(ssid, password);
  
  Serial.println("MAC: " + WiFi.macAddress());
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  Serial.println(WiFi.localIP());
  Serial.println("martin");
  Serial.print("this is ");Serial.print(__FILE__);Serial.print(": ");Serial.print(__DATE__);Serial.print(": ");Serial.println(__TIME__);
  delay(1000UL);
  //einige inits fuer den Taktgeber
  refreshRate = 60/tUpDateStep1; //der Display - refresh erfolgt alle  ...sekunden
  tFadeAway = refreshRate -5;   // Display-fadeOut soll 5 sec f.vor einem update erfolgen  
  // das FS ist mehr als cryptisch :(
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");return;} else {
     f1 = LittleFS.open("index.htm", "r");
      if (!f1){Serial.print("unable to opne index.htm");}
    }
     Serial.println();
while (f1.available()) {Serial.write(f1.read()); }
f1.close();


//-----------------------------

#pragma region checkFlash
/* uint32_t realSize = ESP.getFlashChipRealSize();
 uint32_t ideSize = ESP.getFlashChipSize();
  FlashMode_t ideMode = ESP.getFlashChipMode();
  
  Serial.printf ("Flash-Real-ID:% 08X \n", ESP.getFlashChipId ());
  Serial.printf ("Flash-Realgröße:% u Bytes \n \n", realSize);
  
  Serial.printf ("Flash-Ide-Größe:% u Bytes \n", ideSize);
  Serial.printf ("Flash-Ide-Geschwindigkeit:% u Hz \n", ESP.getFlashChipSpeed());
  Serial.printf ("Flash-Ide-Modus:% s \n", (ideMode == FM_QIO? "QIO": ideMode == FM_QOUT? "QOUT": ideMode == FM_DIO? "DIO": ideMode == FM_DOUT? "DOUT " : "UNBEKANNT"));
  
  if (ideSize != realSize) {
    Serial.println ("Flash-Chip-Konfiguration falsch! \ N");
  } else {
    Serial.println ("Flash Chip Konfiguration ok. \ N");
  }
  
  delay(5000);
*/
#pragma endregion

//--------------------------------

 server.begin();
 //---------------------------Server CGI Stack------------------------------------------>
 #pragma region serverCGI
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", String(), false, processor);
  });

  server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request){
    char str[16]; 

    sprintf(str,"%02u:%02u:%02u ", hours, minutes, seconds); 
    Serial.println(str);
    String test = String(str);
    request->send_P(200, "text/plain", test.c_str());
  });
 
    server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      hours = inputMessage.toInt();
    }
    // GET input2 value on <ESP_IP>/get?input2=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_2)) {
      inputMessage = request->getParam(PARAM_INPUT_2)->value();
      minutes = inputMessage.toInt();
    }
    // GET input3 value on <ESP_IP>/get?input3=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_3)) {
      inputMessage = request->getParam(PARAM_INPUT_3)->value();
      seconds = inputMessage.toInt();
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/html", "HTTP GET request sent to your ESP on input field (" 
                                      ") with value: " + inputMessage +
                                     "<br><a href=\"/\">Return to Home Page</a>");
  });
  #pragma endregion
 //---------------------------/ServerStack CGI------------------------------------------>  
 
  /*
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  */
//  timeClient.begin();
    //END WIFI + TIME
  strip.Begin();
  strip.Show();
}
//-------------------------------------END OF SETUP-------------------------->
//---------------------------------------SET NEW TIME------------------------------------->
// boolean setNewTime1(){
//     static int secondsPrevious = 0; 
//     //refreshRate = sekündliche tUpDateStep1, wurde errechnet in *SetUp' aus User Preferences
//     //tFadeAway = Zeit zum Ausblenden des Displays, im Setup auf 'refreshRate - 5 sec' gesetzt 
//     timeNow = millis()/1000UL; 
//     seconds = (int)(timeNow - timeLast);
//     if (flagSetAt != seconds) { //verhindere mehrfachauslösung, falls funktion in der gleichen sekunde wieder zurückkehrt!!!
        
//         if (seconds >= tUpdate) { displayUpdateFlag = true;
//                                   tUpdate = tUpdate + refreshRate;
//                               flagSetAt = seconds;Serial.println("dy-update!");
//                              }
                             
//                              }
    
//         if (seconds >= 60) {
//         timeLast = timeNow;  //rückspeichern 
//         seconds = 0; 
//         tUpdate = 0;
//         minutes = minutes + 1;}
//         //displayUpdateFlag = true; //neueMinute-Update notwendig!
//           if (minutes >= 60){ 
//                minutes = 0;
//                hours = hours + 1;}
//               // if one hour has passed, start counting minutes from zero and add one hour to the clock
//           if (hours >= 24){
//     hours = 0;
//   }
// if (secondsPrevious != seconds) {
// Serial.print("current HHMMss "); Serial.print(hours); Serial.print(":");Serial.print(minutes);Serial.print(":");Serial.println(seconds); 
 
//  secondsPrevious  = seconds;
// }
//   //if 24 hours have passed , add one day
// /*
// if (hours ==(24 - startingHour) && correctedToday == 0){
//   delay(dailyErrorFast*1000);
//   seconds = seconds + dailyErrorBehind;
//   correctedToday = 1;
// }

// //every time 24 hours have passed since the initial starting time and it has not been reset this day before, add milliseconds or delay the progran with some milliseconds. 
// //Change these varialbes according to the error of your board. 
// // The only way to find out how far off your boards internal clock is, is by uploading this sketch at exactly the same time as the real time, letting it run for a few days 
// // and then determine how many seconds slow/fast your boards internal clock is on a daily average. (24 hours).

// if (hours == 24 - startingHour + 2) { 
//   correctedToday = 0;
// }
// */
// /* Serial.print("HHMMSS: ");Serial.print(hours);
// Serial.print(":");Serial.print(minutes);
// Serial.print(":");Serial.println(seconds); */
// //delay(1500UL);

// return displayUpdateFlag;

// }
// //----------------------------------------------------------end of SetNewTime1----------------------------->
boolean setNewTime2(){
    static int secondsPrevious = 0; 
    //refreshRate = sekündliche tUpDateStep1, wurde errechnet in *SetUp' aus User Preferences
    //tFadeAway = Zeit zum Ausblenden des Displays, im Setup auf 'refreshRate - 5 sec' gesetzt 
 
    timeNow = millis()/1000UL; 
    seconds = (int)(timeNow - timeLast);
 //    if (flagSetAt != seconds) { //verhindere mehrfachauslösung, falls funktion in der gleichen sekunde wieder zurückkehrt!!!
   //      if (seconds >= tUpdate) { displayUpdateFlag = true;
     //                             tUpdate = tUpdate + refreshRate;
       //                       flagSetAt = seconds;Serial.println("dy-update!");
         //                    }
           //                }
    

        if (seconds >= 60) {
        timeLast = timeNow;  //rückspeichern 
        seconds = 0; 
        tUpdate = 0;
        minutes = minutes + 1;}
    
        //displayUpdateFlag = true; //neueMinute-Update notwendig!
          if (minutes >= 60){ 
               minutes = 0;
               hours = hours + 1;}
              // if one hour has passed, start counting minutes from zero and add one hour to the clock
          if (hours >= 24){
    hours = 0;
  }

    if (seconds == 0) {displayUpdateFlag = true; effectsMode = 1;} else {effectsMode = 2;}
     switch (tUpDateStep1) { //60 /30 /20 /15
        case 2: if (seconds == 30) {displayUpdateFlag = true; } 
        break;
        case 3: if ((seconds == 20) || (seconds == 40)) {displayUpdateFlag = true; } 
        break;
        case 4: if ((seconds == 15) || (seconds == 30) || (seconds == 45))  {displayUpdateFlag = true; } 
        break; 
     }

if (secondsPrevious != seconds) {
Serial.print("current HHMMss "); Serial.print(hours); Serial.print(":");Serial.print(minutes);Serial.print(":");Serial.println(seconds); 
 
 secondsPrevious  = seconds;
}
  //if 24 hours have passed , add one day
/*
if (hours ==(24 - startingHour) && correctedToday == 0){
  delay(dailyErrorFast*1000);
  seconds = seconds + dailyErrorBehind;
  correctedToday = 1;
}

//every time 24 hours have passed since the initial starting time and it has not been reset this day before, add milliseconds or delay the progran with some milliseconds. 
//Change these varialbes according to the error of your board. 
// The only way to find out how far off your boards internal clock is, is by uploading this sketch at exactly the same time as the real time, letting it run for a few days 
// and then determine how many seconds slow/fast your boards internal clock is on a daily average. (24 hours).

if (hours == 24 - startingHour + 2) { 
  correctedToday = 0;
}
*/
/* Serial.print("HHMMSS: ");Serial.print(hours);
Serial.print(":");Serial.print(minutes);
Serial.print(":");Serial.println(seconds); */
//delay(1500UL);
return displayUpdateFlag;
}

//---------------------------------START OF LOOP----------------------------->
void loop() {
syncEffectsMode(myEffectsMode); //sende effectsMode an 256.h 
 // timeClient.update();
  //minutes = minutes + 1;
 // Serial.println("test");
 //    Serial.println(timeClient.getHours());
 //    Serial.println(timeClient.getMinutes());
//--------------------------------SERVER-------------------------------<

  //---------------------------/SERVER--------------------------------------------<
  //clearLeds();
  
  //Time2LED(timeClient.getHours(), timeClient.getMinutes());
  //setCurrentColor(demo);
  if(setNewTime2()) {
 fadeOut();
 setCurrentColor(demo);
 Serial.print("updating HHMMss "); Serial.print(hours); Serial.print(":");Serial.print(minutes);Serial.print(":");Serial.println(seconds); 
   //timeNow = timeNow + 5;
  // Serial.println("-------debug:-----TimeToLed --------------------------");
  
  /* myEffectsMode++;
  if (myEffectsMode > 3) {myEffectsMode =0;} */
  
  Time2LED(hours, minutes);  //Fkt. ist im File TimeLogic.h
  displayUpdateFlag = false; //"neueMinute-Update notwendig?"  zurücksetzen
  }
    //if (!(cc % 10)) {Serial.print("got ClockClick Update:");} cc++;
  //Serial.println(cc);//timeClient.update();
   // strip.Show();
//  server.reset();
    //seconds = seconds + delayInSeconds;
      //delay(delayInSeconds*1000);
}
 
 //------------------------------------END OF LOOP---------------------------------------->


  
