#include <Arduino.h>
#include <NTPClient.h>
#include "256.h"
using namespace std;

void setHourOnLed(int Hour){
    //TOP_UHR();
    switch (Hour) {
    case 0:  TOP_VIER(); TOP_UND(); TOP_ZWANZIG();  break;
    case 1: TOP_EIN();  break;

    case 2:  TOP_ZWEI();  break;
    case 3:  TOP_DREI();  break;
    case 4:  TOP_VIER();  break;
    case 5:  TOP_FUENF(); break;
    case 6:  TOP_SECHS(); break;
    case 7:  TOP_SIEBEN();  break;
    case 8:  TOP_ACHT();  break;
    case 9:  TOP_NEUN();  break;
    case 10: TOP_ZEHN();  break;
    case 11: TOP_ELF();   break;
    case 12: TOP_ZWOELF();  break;
    case 13: TOP_DREI(); TOP_ZEHN();  break;
    case 14: TOP_VIER(); TOP_ZEHN();  break;
    case 15: TOP_FUENF();TOP_ZEHN();  break;
    case 16: TOP_SECHS(); TOP_ZEHN();  break;
    case 17: TOP_SIEB(); TOP_ZEHN(); break;
    case 18: TOP_ACHT(); TOP_ZEHN(); break; //
    case 19: TOP_NEUN();TOP_ZEHN();  break;
    case 20: TOP_ZWANZIG(); break;
    case 21: TOP_EIN(); TOP_UND(); TOP_ZWANZIG();  break;
    case 22: TOP_ZWEI(); TOP_UND(); TOP_ZWANZIG();  break;
    case 23: TOP_DREI(); TOP_UND(); TOP_ZWANZIG();   break;//
    case 24: TOP_VIER(); TOP_UND(); TOP_ZWANZIG();  break;//
  
    default:
        break;
    }
    TOP_UHR();
}

void setMinuteOnLed(int Minute){
 switch(Minute){
      case 0: break;// case 0: BOTTOM_UHR(); break;  // deakt. wg. Doppelanzeige UHR TOP u. UHR BOTTOM  
      case 1: BOTTOM_EINS(); break;
      //case 1: BOTTOM_EINE(); break;
      case 2: BOTTOM_ZWEI(); break;
      case 3: BOTTOM_DREI(); break;
      case 4: BOTTOM_VIER(); break;
      case 5: BOTTOM_FUENF(); break;
      case 6: BOTTOM_SECHS(); break;
      case 7: BOTTOM_SIEBEN();break;
      case 8: BOTTOM_ACHT(); break;
      case 9: BOTTOM_NEUN(); break;
      case 10: BOTTOM_ZEHN(); break;
      case 11: BOTTOM_ELF(); break;
      case 12: BOTTOM_ZWOELF(); break;
      case 13: BOTTOM_DREI(); BOTTOM_ZEHN();break;
      case 14: BOTTOM_VIER(); BOTTOM_ZEHN();break;
      case 15: BOTTOM_FUENF(); BOTTOM_ZEHN();break;
      case 16: BOTTOM_SECHS(); BOTTOM_ZEHN();break;
      case 17: BOTTOM_SIEB(); BOTTOM_ZEHN();break;
      case 18: BOTTOM_ACHT(); BOTTOM_ZEHN();break;
      case 19: BOTTOM_NEUN(); BOTTOM_ZEHN();break;
      case 20: BOTTOM_ZWANZIG(); break;
      case 21: BOTTOM_EIN(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 22: BOTTOM_ZWEI(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 23: BOTTOM_DREI(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 24: BOTTOM_VIER(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 25: BOTTOM_FUENF(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 26: BOTTOM_SECHS(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 27: BOTTOM_SIEBEN(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 28: BOTTOM_ACHT(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 29: BOTTOM_NEUN(); BOTTOM_UND(); BOTTOM_ZWANZIG();break;
      case 30: BOTTOM_DREISSIG(); break;
      case 31: BOTTOM_EIN(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 32: BOTTOM_ZWEI(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 33: BOTTOM_DREI(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 34: BOTTOM_VIER(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 35: BOTTOM_FUENF(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 36: BOTTOM_SECHS(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 37: BOTTOM_SIEBEN(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 38: BOTTOM_ACHT(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 39: BOTTOM_NEUN(); BOTTOM_UND(); BOTTOM_DREISSIG();break;
      case 40: BOTTOM_VIERZIG(); break;
      case 41: BOTTOM_EIN(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 42: BOTTOM_ZWEI(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 43: BOTTOM_DREI(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 44: BOTTOM_VIER(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 45: BOTTOM_FUENF(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 46: BOTTOM_SECHS(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 47: BOTTOM_SIEBEN(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 48: BOTTOM_ACHT(); BOTTOM_UND(); BOTTOM_VIERZIG();break;
      case 49: BOTTOM_NEUN(); BOTTOM_UND(); BOTTOM_VIERZIG();break;      
      case 50: BOTTOM_FUENFZIG(); break;
      case 51: BOTTOM_EIN(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 52: BOTTOM_ZWEI(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 53: BOTTOM_DREI(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 54: BOTTOM_VIER(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 55: BOTTOM_FUENF(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 56: BOTTOM_SECHS(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 57: BOTTOM_SIEBEN(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 58: BOTTOM_ACHT(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;
      case 59: BOTTOM_NEUN(); BOTTOM_UND(); BOTTOM_FUENFZIG();break;    
     }
}

int textCtxt = 0; // informiert die effectRoutinen, in welchem Context der anzuzeigende Text steht
void Time2LED(int Hour, int Minute){

    
        textCtxt = 1;
        es_ist();
        textCtxt = 2;
        setHourOnLed(Hour);
        textCtxt = 3;
        setMinuteOnLed(Minute);
    
    
}

int getContext() {
    return textCtxt;
}



