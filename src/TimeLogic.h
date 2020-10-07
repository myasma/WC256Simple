#include <Arduino.h>
#include <NTPClient.h>
#include "256.h"

using namespace std;

void setHourOnLED(int Hour){
    switch (Hour)
    {
    case 0:
        NULL_TOP();
        break;
    case 1:
        EIN_TOP();
        break;
    case 2:
        ZWEI_TOP();
        break;
    case 3:
        DREI_TOP();
        break;
    case 4:
        VIER_TOP();
        break;
    case 5:
        FUENF_TOP();
        break;
    case 6:
        SECHS_TOP();
        break;
    case 7:
        SIEBEN_TOP();
        break;
    case 8:
        ACHT_TOP();
        break;
    case 9:
        NEUN_TOP();
        break;
    case 10:
        ZEHN_TOP();
        break;
    case 11:
        ELF_TOP();
        break;
    case 12:
        ZWOELF_TOP();
        break;
    case 13:
        DREI_TOP();
        ZEHN_TOP();
        break;
    case 14:
        VIER_TOP();
        ZEHN_TOP();
        break;
    case 15:
        FUENF_TOP();
        ZEHN_TOP();
        break;
    case 16:
        SECHS_TOP();
        ZEHN_TOP();
        break;
    case 17:
        SIEB_TOP();
        ZEHN_TOP();
        break;
    case 18:
        ACHT_TOP();
        ZEHN_TOP();
        break;
    case 19:
        NEUN_TOP();
        ZEHN_TOP();
        break;
    case 20:
        ZWANZIG_TOP();
        break;
    case 21:
        EIN_TOP();
        UND();
        ZWANZIG_TOP();
        break;
    case 22:
        ZWEI_TOP();
        UND();
        ZWANZIG_TOP();
        break;
    case 23:
        DREI_TOP();
        UND();
        ZWANZIG_TOP();
        break;
    default:
        break;
    }
}

void setMinuteHelper(int Minute){
    int value = Minute;
    if(Minute > 10) {
        value = Minute % 10;
    }
    UHR_TOP();
    switch (value)
    {
    case 1:
        EIN_BOTTOM();
        break;
    case 2:
        ZWEI_BOTTOM();
        break;
    case 3:
        DREI_BOTTOM();
        break;
    case 4:
        VIER_BOTTOM();
        break;
    case 5:
        FUENF_BOTTOM();
        break;
    case 6:
        SECHS_BOTTOM();
        break;
    case 7:
        if(Minute == 17) {
            SIEB_BOTTOM();
            break;
        }else 
        SIEBEN_BOTTOM();
        break;
    case 8:
        ACHT_BOTTOM();
        break;
    case 9:
        NEUN_BOTTOM();
        break;
    
    default:
        break;
    }
}

void setMinuteOnLED(int Minute){
    switch (Minute)
    {
    case 0:
        UHR_BOTTOM();
        break;
    case 1:
        UHR_TOP();
        EINS_BOTTOM();
        break;
    case 2 ... 6:
        setMinuteHelper(Minute);
        break;
    case 7:
        UHR_TOP();
        SIEBEN_BOTTOM();
        break;
    case 8 ... 9:
        setMinuteHelper(Minute);
        break;
    case 10:
        UHR_TOP();
        ZEHN_BOTTOM();
        break;
    case 11:
        UHR_TOP();
        ELF_BOTTOM();
        break;
    case 12:
        ZWOELF_BOTTOM();
        UHR_TOP();
        break;
    case 13 ... 19:
        setMinuteHelper(Minute);
        ZEHN_BOTTOM();
        break;
    case 20:
        ZWANZIG_BOTTOM();
        UHR_TOP();
        break;
    case 21 ... 29:
        setMinuteHelper(Minute);
        UND_BOTTOM();
        ZWANZIG_BOTTOM();
        break;
    case 30:
        UHR_TOP();
        DREISSIG_BOTTOM();
        break;
    case 31 ... 39:
        UHR_TOP();
        DREISSIG_BOTTOM();
        UND_BOTTOM();
        setMinuteHelper(Minute);
        break;
    case 40:
        UHR_TOP();
        VIERZIG_BOTTOM();
        break;
    case 41 ... 49:
        UHR_TOP();
        VIERZIG_BOTTOM();
        UND_BOTTOM();
        setMinuteHelper(Minute);
        break;
    case 50:
        UHR_TOP();
        FUENFZIG_BOTTOM();
        break;
    case 51 ... 59:
        UHR_TOP();
        FUENFZIG_BOTTOM();
        UND_BOTTOM();
        setMinuteHelper(Minute);
        break;


    default:
        break;
    }
}


void Time2LED(int Hour, int Minute){
    if(Hour == 0 && Minute <= 5) {
        MITTERNACHT();
    }
    
    else {
       ES_IST();
        setHourOnLED(Hour);
        setMinuteOnLED(Minute);
        
    }
    
}





