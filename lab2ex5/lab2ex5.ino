#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define BUTTON_SELECT 1

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

}

void loop() {
  int button_state = lcd.readButtons();
  if (button_state && BUTTON_SELECT) {
    lcd.clear();
  }
  else {
    unsigned long time = millis();
    lcd.setCursor(0,0);
    lcd.print(time);
  }
}
