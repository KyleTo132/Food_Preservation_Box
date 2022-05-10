#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);
double temp_1 = 0;
double temp_2 = 0;
double tempC = 0;

// Addresses of 2 DS18B20s
uint8_t sensor1[8] = { 0x28, 0xEE, 0xFB, 0x07, 0xD6, 0x01, 0x3C, 0x65 };
uint8_t sensor2[8] = { 0x28, 0x1F, 0x8B, 0x07, 0xD6, 0x01, 0x3C, 0x4D };

void setup(void)
{
  lcd.init();
  lcd.clear();           
//-----Turn on the blacklight and print a message----
  lcd.backlight();
  lcd.setCursor(1,0);                   //Set cursor to character 2 on line 0
  lcd.print("Sensor Project!");
  lcd.setCursor(3,1);                   //Move cursor to character 2 on line 1
  lcd.print("AuTOrium");
  delay(2000);
}

void loop(void)
{
  sensors.requestTemperatures();
  lcd.setCursor(0,0);
  lcd.print("SENSOR1: ");
  printTemperature(sensor1);
  temp_1 = sensors.getTempCByIndex(sensor1);
  Serial.print("Temp1: "); 
  Serial.println(temp_1);


  
  lcd.setCursor(0,1);
  lcd.print("SENSOR2: ");
  printTemperature(sensor2);
  temp_2 = sensors.getTempCByIndex(sensor2);
  Serial.print("Temp1: "); 
  Serial.println(temp_2);



}


  void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
 
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C");
}
