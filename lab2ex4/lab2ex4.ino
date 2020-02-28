#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readString();
    if (str.length() > 16) {
      for (int i = 0; i < str.length(); i++) {
        lcd.print(str);
        lcd.scrollDisplayRight();
        lcd.setCursor(0,0);
        delay(500);
      }
    }
  }

}
