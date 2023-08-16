//code based on https://www.electronics-lab.com/project/arduino-weather-station-using-dht11/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 16, 2);

//DHT11 pin connected declaration
dht DHT;
#define DHT11_PIN 2

void setup() 
{
lcd.begin();//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Sebastian FM");
lcd.setCursor(0,1);
lcd.print("Weather Station");
delay(10000);
}

void loop() 
{
//step1: reading temperature and humidity from DHT11
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Reading sensor");
float temperature, humidity, temperatureF;
int d = DHT.read11(DHT11_PIN);
humidity = DHT.humidity;
temperature = DHT.temperature;
//converting Celcius input to Farenheit
temperatureF = (temperature * 1.8) + 32;
delay(5000);

//converting numeric data float to string data
char tempC[6];
char tempF[6];
char humF[6];
//syntax(floatValue, minStringWidht, numAfterDecimal, outputVar)
dtostrf(temperature, 5, 1, tempC);
dtostrf(temperatureF, 5, 1, tempF);
dtostrf(humidity, 2, 0, humF);

//step 3: sending the weather data to the display
lcd.clear();
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("Temp:"); 
lcd.print(tempC);
lcd.print((char)223); //printing the ° symbol
lcd.print("C "); //short rep of Centrigrades
delay(1000);//Delay used to give a dynamic effect
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("Temp:");
lcd.print(tempF);
lcd.print((char)223); //printing the ° symbol
lcd.print("F "); //short rep of Centrigrades
delay(5000); 
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Humi:");
lcd.print(humF);
lcd.print("%");
delay(3000);//Delay used to give a dynamic effect
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
//scale according to: https://www.sensitivechoice.com/resource/indoor-humidity-levels/
if(humidity > 29 && humidity < 61 ) {
  lcd.print("Healthy");
} else {
  lcd.print("Dangerous");
}
delay(20000); 
}
