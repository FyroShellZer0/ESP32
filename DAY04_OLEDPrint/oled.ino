#include <Adafruit_GFX.h>
#include  <Adafruit_SSD1306.h>
#include <Wire.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
  Wire.begin(21, 22); //pins
  //try address 0x3C first
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true); //oled not found
  }
  

display.clearDisplay(); //clear buffer
display.setTextSize(1); //small text (adjustable)
display.setTextColor(SSD1306_WHITE); //white text
display.setCursor(0, 0); //top left
display.println("Hello!");
display.println("I am working!");
display.display(); //show on screen
}
void loop(){}
