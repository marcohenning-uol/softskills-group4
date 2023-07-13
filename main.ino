#include <ArduinoJson.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>
WiFiManager wifiManager;
WiFiClient client;
HTTPClient http;

#define DATA 4

const String CITY = "Oldenburg";
const String API_KEY = "XXXXXXXXXX";
const String IFTTT_API_KEY = "XXXXXXXXXX";

int weatherID = 0;
int weatherID_shortened = 0;
int weatherID_last_shortened = 0;
unsigned long lastcheck = 0;


void setup() {
  Serial.begin(9600);
  pinMode(DATA, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  wifiManager.autoConnect("SWF", "123456789");
  delay(2000);
  getCurrentWeatherConditions();
}

void loop() {
  int data = digitalRead(DATA);
  if (data == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
  if (millis() - lastcheck >= 300000) {
    getCurrentWeatherConditions();
    lastcheck = millis();
    if ((weatherID_shortened == 3 || weatherID_shortened == 5) && weatherID_last_shortened != 3 && weatherID_last_shortened != 5) {
      if (data == 0) {
        http.begin(client, "http://maker.ifttt.com/trigger/send_email/with/key/" + IFTTT_API_KEY);
        http.GET();
      }
    }
  }
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
