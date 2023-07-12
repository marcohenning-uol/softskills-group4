#include <ArduinoJson.h>
#include <WiFiManager.h>
WiFiManager wifiManager;
WiFiClient client;


const String CITY = "Oldenburg";
const String API_KEY = "XXXXXXXXXX";

int weatherID = 0;
int weatherID_shortened = 0;
int weatherID_last_shortened = 0;
unsigned long lastcheck = 0;


void setup() {
  Serial.begin(9600);
  pinMode(DATA, INPUT);
  wifiManager.autoConnect("SWF", "123456789");
  delay(2000);
  getCurrentWeatherConditions();
}

void loop() {
}

void getCurrentWeatherConditions() {
  if (client.connect("api.openweathermap.org", 80)) {
    client.println("GET /data/2.5/weather?q=" + CITY + ",DE&units=metric&lang=de&APPID=" + API_KEY);
    client.println("Host: api.openweathermap.org");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  const size_t capacity = JSON_ARRAY_SIZE(2) + 2 * JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(14) + 360;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, client);
  client.stop();

  weatherID_last_shortened = weatherID_shortened;
  weatherID = doc["weather"][0]["id"];
  weatherID_shortened = weatherID / 100;
  Serial.println("Weather ID: " + String(weatherID_shortened));
}
