#include <LiquidCrystal_I2C.h>
#include "DHT.h"
//#include "Chara.c"

#define DHTPIN 2
#define DHTTYPE DHT11

int autoMode = 1;

int modeDelay = 1000;

float temp = 0;
float humi = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
DHT dht(DHTPIN, DHTTYPE);

//byte charAuto[8];
byte charDegr[8] = {
  0b11000,
  0b11000,
  0b00110,
  0b01001,
  0b01000,
  0b01001,
  0b00110,
  0b00000
};

byte charAuto[8] = {
  0b01100,
  0b10010,
  0b00111,
  0b00010,
  0b01000,
  0b11100,
  0b01001,
  0b00110
};

byte charLeft0[8] = {
  0b01000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b01000
};

byte charRight0[8] = {
  0b00010,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00010
};

// Modes
// 0: Initializing
// 1: Temperature
// 2: Humidity
// 3: PM25
// 4: Light level

int mode = 0;


void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, charAuto);
  lcd.createChar(1, charDegr);
  lcd.createChar(2, charLeft0);
  lcd.createChar(3, charRight0);
  
  mode0();
}

void loop() {
  if (modeDelay < 0) {
    mode += 1;

    modeDelay = 1000;
  
    if (mode == 1)
      mode1();
    else if (mode == 2)
      mode2();
    else
      mode = 1;

  }

  lcd.setCursor(0, 1);
  lcd.print(mode);

  modeDelay--;
}
