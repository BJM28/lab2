#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4

#define BUTTON_SELECT 1
#define BUTTON_RIGHT 2
#define BUTTON_LEFT 16
#define BUTTON_DOWN 4
#define BUTTON_UP 8


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  int button_state = lcd.readButtons();
  if (button_state) {
    if (button_state & BUTTON_SELECT) {
      lcd.setBacklight(RED);
    }
    if (button_state & BUTTON_RIGHT) {
      lcd.clear();
      lcd.setBacklight(YELLOW);
    }
    if (button_state & BUTTON_LEFT) {
      lcd.clear();
      lcd.setBacklight(GREEN);
    }
    if (button_state & BUTTON_DOWN) {
      lcd.clear();
      lcd.setBacklight(TEAL);
    }
    if (button_state & BUTTON_UP) {
      lcd.clear();
      lcd.setBacklight(BLUE);
    }
  }
}
