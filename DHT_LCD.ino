
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

  #define DHTPIN 2     
  #define DHTTYPE DHT11   
  
  LiquidCrystal_I2C lcd(0x27,16,2);
  DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  lcd.init();                     
  lcd.backlight();
  

  dht.begin();
}

void loop() {
  delay(2000);
  lcd.clear();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
   lcd.setCursor(0,0);
   lcd.print("humid : ");
   lcd.setCursor(8,0);
   lcd.print(h);
  
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  // Serial.print(f);
  // Serial.print(F("°F  Heat index: "));
  // Serial.print(hic);
  // Serial.print(F("°C "));
  // Serial.print(hif);
  // Serial.println(F("°F"));
}
