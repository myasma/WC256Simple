#include <Arduino.h>

/* unsigned long  timeNow, timeLast;
,seconds;  */
int minutes, hours;
void setNewTime(){
      timeNow = millis() /1000; 
    seconds = (int) timeNow - timeLast;
    if (seconds == 60) {
        timeLast = timeNow;
        minutes = minutes + 1;
    }

    //if one minute has passed, start counting milliseconds from zero again and add one minute to the clock.

    if (minutes == 60){ 
        minutes = 0;
        hours = hours + 1;
    }

// if one hour has passed, start counting minutes from zero and add one hour to the clock

if (hours == 24){
  hours = 0;
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
}
