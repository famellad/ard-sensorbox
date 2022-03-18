#include <LiquidCrystal_I2C.h>
#include "DHT.h"
//#include "Chara.c"

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
DHT dht(DHTPIN, DHTTYPE);

//byte charAuto[8];
byte charDegr[8] = {
  0b11000,
  0b11000,
  0b00110,
  0b01001,
  0b01000,
  0b01000,
  0b01001,
  0b00110
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

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humi: ");

  lcd.createChar(0, charAuto);
  lcd.createChar(1, charDegr);
  lcd.createChar(2, charLeft0);
  
  dht.begin();
}

void loop() {
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  lcd.setCursor(6, 0);
  lcd.print((int)temp);
  lcd.setCursor(8, 0);
  lcd.write((byte)1);

  lcd.setCursor(6, 1);
  lcd.print((int)humi);
  lcd.setCursor(8, 1);
  lcd.print("%");

  lcd.setCursor(15, 0);
  lcd.write((byte)2);
  
  delay(2000);
}
