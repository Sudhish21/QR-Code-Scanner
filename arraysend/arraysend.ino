#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include "qrcodes.h"


#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin


// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
byte income;
byte qrcode [1000];
//int buf[4];
void setup() {
 Serial.begin(9600);
 Serial.setTimeout(1);
  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(0);
  tft.fillScreen(BLACK);
  tft.setCursor(0,0);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  
}
int i = 0;
int j = 0;
void loop() {
if(Serial.available() > 0){
  qrcode[i] = Serial.read();
  i+=1;
    if(i==980){
    tft.drawBitmap(0,28*j, qrcode1, 280,28, BLACK, WHITE);
       j+=1;
    i = 0;
    }
}

}
//tft.drawBitmap(0,0, qrcode2, 300,300, BLACK,WHITE);
//}
