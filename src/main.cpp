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
//#include "internalTimeClock.h"
//#include <effects.h> 
//accesspoint
#include <Hash.h>
using namespace std;
const char* ssid     = "WORD_CLOCK52";
const char* password = "123456789";

AsyncWebServer server(80);
int dummyVar = 0;

int delayInSeconds = 0;
unsigned long timeNow = 0UL;
unsigned long timeLast = 0UL;
int seconds = 0;
int minutes = 22;
int hours   = 15;
boolean newMinuteFlag = true; //"neueMinute-Update notwendig?"  zurücksetzen
int cc = 0;

//Input Parameter for Webserver
const char* PARAM_INPUT_1 = "HOUR";
const char* PARAM_INPUT_2 = "MINUTE";
const char* PARAM_INPUT_3 = "SECOND";

const long utcOffsetInSeconds = 3600;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time

String processor(const String& var){
  Serial.println(var);

   if(var == "MINUTE"){
    return String(minutes);
  } else if (var =="SECOND"){
    return String(seconds);
    
  }
  else if (var =="HOUR"){
    
    return String(hours);
  }
  else return "uups";
 
}

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
  Serial.print("this is ");Serial.print(_FILENAME_);Serial.print(": ");Serial.print(__DATE__);Serial.print(": ");Serial.println(__TIME__);
  delay(1000UL);
  
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
 
 
 //---------------------------Server Stack------------------------------------------>
 
 //---------------------------/ServerStack------------------------------------------>  
 
  server.begin();

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
boolean setNewTime1(){
    
    timeNow = micros()/1000000UL; 
    seconds = (int)(timeNow - timeLast);
    
     if (seconds >= 60) {
      timeLast = timeNow;  //rückspeichern 
      seconds = 0;
      minutes = minutes + 1;
      newMinuteFlag = true; //neueMinute-Update notwendig!
  
  if (minutes >= 60){ 
      minutes = 0;
      hours = hours + 1;
  

// if one hour has passed, start counting minutes from zero and add one hour to the clock

  if (hours >= 24){
    hours = 0;
  }}}

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
delay(1234UL);
return newMinuteFlag;
}
//---------------------------------START OF LOOP----------------------------->
void loop() {

 // timeClient.update();
  //minutes = minutes + 1;
 // Serial.println("test");
 //    Serial.println(timeClient.getHours());
 //    Serial.println(timeClient.getMinutes());
//--------------------------------SERVER-------------------------------<
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
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
  //---------------------------/SERVER--------------------------------------------<
  clearLeds();
  
  //Time2LED(timeClient.getHours(), timeClient.getMinutes());
  setCurrentColor(violet);
  if(setNewTime1()) {
 
   //timeNow = timeNow + 5;
  // Serial.println("-------debug:-----TimeToLed --------------------------");
  
  Time2LED(hours, minutes);
  newMinuteFlag = false; //"neueMinute-Update notwendig?"  zurücksetzen
  }
    //if (!(cc % 10)) {Serial.print("got ClockClick Update:");} cc++;
  //Serial.println(cc);//timeClient.update();
   // strip.Show();
//  server.reset();
    seconds = seconds + delayInSeconds;
      //delay(delayInSeconds*1000);
  }
 
 //------------------------------------END OF LOOP---------------------------------------->


  
