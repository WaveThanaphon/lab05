#include <TFT_eSPI.h>
#include "DHT.h"
#include <Adafruit_NeoPixel.h>

#define DHTPIN 0
#define DHTTYPE DHT11

#define PINPIXELS 2
#define NUMPIXELS 12

TFT_eSPI tft;

DHT dht(DHTPIN, DHTTYPE);

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PINPIXELS, NEO_GRB + NEO_KHZ800);

void setup() {
  tft.begin();
  dht.begin();
  pixels.begin();
  pixels.setBrightness(50);
  pixels.show();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("DHT", 80, 20);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  Serial.begin(9600);
  pixels.setPixelColor(5, pixels.Color(255, 0, 0));
  pixels.setPixelColor(6, pixels.Color(0, 255, 0));
  pixels.show();
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  tft.drawString("Temp: " + String(temp) + String(" C    "), 80, 40);
  tft.drawString("Humi: " + String(humi) + String(" %    "), 80, 60);
  delay(500);
  if (temp == 30) {
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));
    pixels.setPixelColor(6, pixels.Color(100, 255, 100));
    pixels.setPixelColor(5, pixels.Color(255, 100, 100));
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    Serial.println("30");
  } else if (temp >= 31 and temp < 32) {
    pixels.setPixelColor(4, pixels.Color(51, 204, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    Serial.println("31");
  } else if (temp >= 32 and temp < 33) {
    pixels.setPixelColor(4, pixels.Color(51, 204, 0));
    pixels.setPixelColor(3, pixels.Color(102, 153, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    Serial.println("32");
  } else if (temp >= 33 and temp < 34) {
    pixels.setPixelColor(4, pixels.Color(51, 204, 0));
    pixels.setPixelColor(3, pixels.Color(102, 153, 0));
    pixels.setPixelColor(2, pixels.Color(153, 102, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    Serial.println("33");
  } else if (temp >= 34 and temp < 35) {
    pixels.setPixelColor(4, pixels.Color(51, 204, 0));
    pixels.setPixelColor(3, pixels.Color(102, 153, 0));
    pixels.setPixelColor(2, pixels.Color(153, 102, 0));
    pixels.setPixelColor(1, pixels.Color(204, 51, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    Serial.println("34");
  } else if (temp >= 35) {
    pixels.setPixelColor(4, pixels.Color(51, 204, 0));
    pixels.setPixelColor(3, pixels.Color(102, 153, 0));
    pixels.setPixelColor(2, pixels.Color(153, 102, 0));
    pixels.setPixelColor(1, pixels.Color(204, 51, 0));
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
    Serial.println("35");
  }

  if (temp >= 29 and temp < 30) {
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));
    pixels.setPixelColor(8, pixels.Color(102, 153, 0));
    pixels.setPixelColor(7, pixels.Color(51, 204, 0));
    pixels.show();
    Serial.println("29");
  } else if (temp >= 28 and temp < 29) {
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));
    pixels.setPixelColor(9, pixels.Color(153, 102, 0));
    pixels.setPixelColor(8, pixels.Color(102, 153, 0));
    pixels.setPixelColor(7, pixels.Color(51, 204, 0));
    pixels.show();
    Serial.println("28");
  } else if (temp >= 27 and temp < 28) {
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));
    pixels.setPixelColor(10, pixels.Color(204, 51, 0));
    pixels.setPixelColor(9, pixels.Color(153, 102, 0));
    pixels.setPixelColor(8, pixels.Color(102, 153, 0));
    pixels.setPixelColor(7, pixels.Color(51, 204, 0));
    pixels.show();
    Serial.println("27");
  } else if (temp < 27) {
    pixels.setPixelColor(11, pixels.Color(255, 0, 0));
    pixels.setPixelColor(10, pixels.Color(204, 51, 0));
    pixels.setPixelColor(9, pixels.Color(153, 102, 0));
    pixels.setPixelColor(8, pixels.Color(102, 153, 0));
    pixels.setPixelColor(7, pixels.Color(51, 204, 0));
    pixels.show();
    Serial.println("26");
  }
}
