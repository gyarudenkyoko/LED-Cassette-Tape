#include "FastLED.h"
#include <EEPROM.h>
#define NUM_LEDS 10 //LEDの数

CRGB leds[NUM_LEDS];
#define PIN 0 //LEDのDINを接続しているマイコンボードのピン

//色指定 http://fastled.io/docs/3.1/struct_c_r_g_b.html
//コンパイルしたときに#include EEPROM.hの部分にエラーが出る場合は下記リンクを開いて
//https://github.com/digistump/DigistumpArduino/issues/34
//ページ内のEEPRPM.zipをダウンロードして、
//ArduinoIDEのスケッチ→ライブラリをインクルード→zip形式のライブラリをインストールでEEPRPMをインストールしてからコンパイルする

void setup()
{
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  }

void loop() {
  //指定の色ですべてのLEDを指定の時間光らせる
  fill_solid( &(leds[0]), NUM_LEDS, CRGB::DeepPink); //光らせる色を指定
  FastLED.show(); //LEDを光らせる
  delay(10000); //()の中の数字で待つ（光らせる）時間を指定 単位はms 1000ms＝１秒）

  //指定の色で点滅させる
  FadeInOut(0xFF, 0x14, 0x93); // DeepPink =0xFF1493  ()の中にカラーコードを3分割して頭にそれぞれ0x(ゼロエックス)をつけて,で区切って記載する

 //色を変えて点滅を増やしたバージョン
  fill_solid( &(leds[0]), NUM_LEDS, CRGB::MediumPurple); //
  FastLED.show();
  delay(10000);
  
  FadeInOut(0x93, 0x70, 0xDB); //  MediumPurple =0x9370DB
  FadeInOut(0x93, 0x70, 0xDB); //  MediumPurple =0x9370DB
  
  //虹色に光らせる
  rainbowCycle(100); //()の中の数字を変更すると虹色の変更速度が変わる。数が小さいほど早い
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

void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUM_LEDS; i++) {
      c=Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    showStrip();
    delay(SpeedDelay);
  }
}

// used by rainbowCycle and theaterChaseRainbow
byte * Wheel(byte WheelPos) {
  static byte c[3];
 
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}



// ***************************************
// ** FastLed/NeoPixel Common Functions **
// ***************************************

// Apply LED color changes
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

// Set a LED color (not yet visible)
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

// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
