#include <Arduino.h>
#include <NeoPixelBus.h>
using namespace std;

static uint16_t PixelCount = 256;
static uint8_t DotDataPin = 2;  
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, DotDataPin);
static RgbColor Red     {  20,0,0};
static RgbColor White      = RgbColor(100,100,100);
static RgbColor Black      = RgbColor(0,0,0);
static RgbColor demo        =RgbColor(255,255,120);
RgbColor currentColor;

void setCurrentColor(RgbColor color){currentColor = color;}

void clearLeds(){
    for(int i = 0; i < PixelCount; ++i){
        strip.SetPixelColor(i, Black);
    }
}

void setLed(int pos){
    strip.SetPixelColor(pos, currentColor);
}