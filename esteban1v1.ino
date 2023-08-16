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
delay(3000);
}

void loop() 
{
//step1: reading temperature and humidity from DHT11
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Reading sensor");
float temperature, humidity;
int d = DHT.read11(DHT11_PIN);
humidity = DHT.temperature;
temperature = DHT.humidity;
delay(2000);

//converting numeric data to string data
char tempF[6];
char humF[6];
dtostrf(temperature, 5, 1, tempF);
dtostrf(humidity, 2, 0, humF);

//step 3: sending the weather data to the display
lcd.clear();
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("");
lcd.print("Temp:"); 
lcd.print(tempF);
lcd.print((char)223); //printing the ° symbol
lcd.print("C "); //short rep of Centrigrades
delay(1000);//Delay used to give a dynamic effect
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("Humi:");
lcd.print(humF);
lcd.print("%");
delay(10000); 

}
