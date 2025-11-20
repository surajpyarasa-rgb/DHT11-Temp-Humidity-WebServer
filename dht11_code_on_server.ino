#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "DHT11 Sensor";
ESP8266WebServer server(80);

float temperatureC = 0.0;
float temperatureF = 0.0;
float humidity = 0.0;

void handleRoot() {
  String html = "<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>DHT11 Sensor</title>\
    <style>\
      body { font-family: Arial; text-align: center; margin-top: 50px; }\
      h1 { color: #333; }\
    </style>\
  </head>\
  <body>\
    <h1>Temperature: " + String(temperatureC, 2) + "°C | " + String(temperatureF, 2) + "°F</h1>\
    <h1>Humidity: " + String(humidity, 2) + "%</h1>\
  </body>\
  </html>";
  
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.softAP(ssid);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  temperatureC = dht.readTemperature();
  temperatureF = dht.readTemperature(true);
  humidity = dht.readHumidity();

  if (isnan(temperatureC) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("°C | ");
  Serial.print(temperatureF);
  Serial.println("°F");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  server.handleClient();
  delay(2000);
}
