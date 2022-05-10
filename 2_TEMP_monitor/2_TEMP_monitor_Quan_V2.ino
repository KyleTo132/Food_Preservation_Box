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

int deviceCount = 0; //đếm có bao nhiêu sensor?

void setup(void)
{
  sensors.begin();
  Serial.begin(9600);
  deviceCount = sensors.getDeviceCount();
  
  lcd.init();
  lcd.clear();           
//-----Turn on the blacklight and print a message----
  lcd.backlight();
  lcd.setCursor(0,0);                   //Set cursor to character 2 on line 0
  lcd.print("Capstone Design");
  lcd.setCursor(0,1);                   //Move cursor to character 2 on line 1
  lcd.print("Group 2");
  delay(2000);
}

void loop(void)
{
  sensors.requestTemperatures();
  lcd.clear();
  lcd.noBlink();
  for (int c = 0; c< deviceCount; c++){
      if (c == 0){
        lcd.setCursor(0,0);
        lcd.print("Temp1: ");
        tempC = sensors.getTempCByIndex(c);
//        Serial.print("Temp1: "); 
        Serial.println(tempC);
        lcd.print(tempC);lcd.print((char)223);lcd.print("C");                 
      }
       if (c == 1){
        lcd.setCursor(0,1);
        lcd.print("Temp2: ");
        tempC = sensors.getTempCByIndex(c);
//       Serial.print("Temp2: "); 
        Serial.println(tempC);
        Serial.print("\n");
        lcd.print(tempC);lcd.print((char)223);lcd.print("C");
       }
    }
}


  void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
 
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C");
}
