#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include "HX711.h"
#define DOUT  23
#define CLK  19
HX711 scale(DOUT, CLK);

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

WebServer server(80);

int liter;
int val;
float weight; 
float calibration_factor = 102500; // change this value for your Load cell sensor 

void handleRoot() {
  String page = "<!DOCTYPE html><html>";
  page += "<head>";
  page += "<meta http-equiv='refresh' content='2'>";
  page += "<title>IV Bag Monitoring</title>";
  page += "<style>";
  page += "body{font-family:Arial;text-align:center;background:#f5f5f5;}";
  page += "h1{color:#0066cc;}";
  page += ".box{background:white;padding:20px;margin:30px auto;width:300px;border-radius:10px;box-shadow:0 0 10px gray;}";
  page += "</style>";
  page += "</head>";

  page += "<body>";
  page += "<div class='box'>";
  page += "<h1>IV Bag Monitoring</h1>";
  page += "<h2>Remaining Volume</h2>";
  page += "<h1>" + String(liter) + " mL</h1>";
  page += "<h2>Remaining</h2>";
  page += "<h1>" + String(val) + "%</h1>";

  if(val <= 20)
    page += "<h2 style='color:red;'>LOW</h2>";
  else if(val <= 50)
    page += "<h2 style='color:orange;'>HALF</h2>";
  else
    page += "<h2 style='color:green;'>NORMAL</h2>";
  page += "</div>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}

void setup() {
  // Set up serial monitor
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(BUZZER ,OUTPUT);
  Serial.println("Remove all weight from scale");
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}
 void loop() {
 measureweight();
}
 
void measureweight(){
 scale.set_scale(calibration_factor); //Adjust to this calibration factor
  weight = scale.get_units(5); 
    if(weight<0)
  {
    weight=0.00;
    }
  liter = weight*1000;
  val = liter;
  val = map(val, 0, 505, 0, 100);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("IOT Based IV Bag");
  lcd.setCursor(2, 1);
  lcd.print("Monitering System");
  Serial.print("Kilogram: ");
  Serial.print(weight); 
  Serial.println(" Kg");
  lcd.setCursor(1, 2);
  lcd.print("IV Bottle = ");
  lcd.print(liter);
  lcd.print(" mL");
  Serial.print("IV BOTTLE: ");
  Serial.print(liter);
  Serial.println("mL");
  lcd.setCursor(1, 3);
  lcd.print("IV Bag Percent=");
  lcd.print(val);
  lcd.print("%");
  Serial.print("IV Bag Percent: ");
  Serial.print(val);
  Serial.println("%");
  Serial.println();
  delay(500);
}
