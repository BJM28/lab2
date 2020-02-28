#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();


#define BUTTON_NONE 0
#define BUTTON_SELECT 1
#define BUTTON_RIGHT 2
#define BUTTON_LEFT 16
#define BUTTON_DOWN 4
#define BUTTON_UP 8

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

}

void loop() {
  delay(500);
  lcd.scrollDisplayRight();
  lcd.setCursor(0,1);
  int button_state = lcd.readButtons();
  int num = button_state;
  while (num > 0) {
    if (num - BUTTON_LEFT >= 0) {
      lcd.print("LEFT ");
      num = num - BUTTON_LEFT;
    }
    else if (num - BUTTON_UP >= 0) {
      lcd.print("UP ");
      num = num - BUTTON_UP;
    }
    else if (num - BUTTON_DOWN >= 0) {
      lcd.print("DOWN ");
      num = num - BUTTON_DOWN;
    }
    else if (num - BUTTON_RIGHT >= 0) {
      lcd.print("RIGHT ");
      num = num - BUTTON_RIGHT;
    }
    else if (num - BUTTON_SELECT >= 0) {
      lcd.print("SELECT ");
      num = num - BUTTON_SELECT;
    }
  }
}
