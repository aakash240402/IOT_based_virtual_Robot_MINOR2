#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
 
double temp_amb;
double temp_obj;
double calibration = 2.36;
 
char auth[] = "teccEkrhvziuYpT3vnETyUejty1NMMLI";    // You should get Auth Token in the Blynk App.
char ssid[] = "esp";                       // Your WiFi credentials.
char pass[] = "12345678";
 
void setup()
{
  Serial.begin(9600);
  mlx.begin();         //Initialize MLX90614
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  Blynk.begin(auth, ssid, pass);
  
  Serial.println("Temperature Sensor MLX90614");
 
  delay(2500);
}
 
void loop()
{
  //Reading room temperature and object temp
  //for reading Fahrenheit values, use
  //mlx.readAmbientTempF() , mlx.readObjectTempF() )
  Blynk.run();
  temp_obj = mlx.readObjectTempF();
 
  //Serial Monitor

  Serial.print("Object temp = ");
  Serial.println(temp_obj);
   
  Blynk.virtualWrite(V2, (temp_obj + calibration));
  
  delay(1000);
}