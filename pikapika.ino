#include "FastLED.h"
#define NUM_LEDS 10 //LEDの数
CRGB leds[NUM_LEDS];
#define PIN 0 //LEDのDINを接続しているマイコンボードのピン

void setup()
{
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

// *** REPLACE FROM HERE ***
void loop() { 
  // ---> here we call the effect function <---

//点滅（フェードイン）
FadeInOut(0x00, 0x00, 0xff); // blue 0x0000ff

//点滅（ストロボ)
Strobe(0x00, 0x00, 0xff, 5, 50, 1000); // blue 0x0000ff

FadeInOut(0xff, 0xff, 0xff); // white
Strobe(0xff, 0xff, 0xff, 5, 50, 1000);

FadeInOut(0xff, 0xf7, 0x00); // yellow
Strobe(0xff, 0xf7, 0x00, 5, 50, 1000);

FadeInOut(0xff, 0xff, 0xff); // white
Strobe(0xff, 0xff, 0xff, 5, 50, 1000);

FadeInOut(0xff, 0x00, 0xd5); // pink
Strobe(0xff, 0x00, 0xd5, 5, 50, 1000);

FadeInOut(0xff, 0xff, 0xff); // white
Strobe(0xff, 0xff, 0xff, 5, 50, 1000);

FadeInOut(0x86, 0xe6, 0x00); // yellowgreen
Strobe(0x86, 0xe6, 0x00, 5, 50, 1000);

FadeInOut(0xff, 0xff, 0xff); // white
Strobe(0xff, 0xff, 0xff, 5, 50, 1000);

}

// ---> here we define the effect function <---
// *** REPLACE TO HERE ***
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }
 
 delay(EndPause);
}


void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
}


void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}
