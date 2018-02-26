//Arc Reactor animation 
//Sheldon McLeod Oct 2015
//Fades lights and transitions collor pallete
//Also uses a potentiomer to control brightness
//Uses Neopixel rings 24,16,12,8

#include "FastLED.h"

#define DATA_PIN    4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];
uint8_t colorIndex =60;
uint8_t theta = 60;
#define BRIGHTNESS        
#define FRAMES_PER_SECOND  120
CRGBPalette16 currentPalette;
CRGBPalette16 currentPalette2;
CRGBPalette16 currentPalette3;
TBlendType    currentBlending;
uint8_t gHue = 0;

#define BPM 55
#define DIMMEST  100
#define BRIGHTEST 255


void setup() {
  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // set master brightness control
  
  
}


void loop()
{   
  //potentiomer
  int val = analogRead(4);
  int light = map(val, 0, 1023, 0, 255);
  FastLED.setBrightness(light);     
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; // motion speed 
    SetPalette();
    FillLEDsFromPaletteColors(startIndex);
   // spin();
    FastLED.show();
    FastLED.delay(100 / FRAMES_PER_SECOND);
}



void SetPalette(){
       currentPalette = CRGBPalette16( CRGB::Cyan, CRGB::Aquamarine, CRGB::DarkGrey, CRGB::Cyan);     
       currentPalette2 = CRGBPalette16( CRGB::MediumBlue, CRGB::Aquamarine, CRGB::Cyan); 
       currentPalette3 = CRGBPalette16( CRGB::Cyan, CRGB::DarkTurquoise, CRGB::Aqua); 
       currentBlending = LINEARBLEND; 
}              
    
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
   
    uint8_t brightness =  beatsin8( BPM, DIMMEST, BRIGHTEST);
    
      for( int i = 0; i < 24; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
         colorIndex += 2;
       }
      for( int i = 24; i < 52; i++) {
        leds[i] = ColorFromPalette( currentPalette2, colorIndex, brightness, currentBlending);
         colorIndex += 1;
       } 
      for( int i = 53; i < 62; i++) {
        leds[i] = ColorFromPalette( currentPalette3, colorIndex, brightness, currentBlending);
         colorIndex += 4;
       } 
   
}

void spin()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos24 = beatsin8(162,0,24);
  int pos16 = beatsin8(62,25,41);
  int pos12 = beatsin16(32,41,52);
  
  //leds[pos24] += CHSV( 100, 0, 100);
  leds[pos16] += CHSV( 100, 0, 0);  
}
