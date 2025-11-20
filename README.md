# DHT11-Temp-Humidity-WebServer
A simple IoT project using the DHT11 sensor and ESP8266 to monitor temperature and humidity over a built-in WiFi web server. Displays real-time sensor values in a browser with auto-refresh capability. Ideal for beginners exploring ESP8266 and web-based sensor monitoring.

# 🌡️ DHT11 Temperature & Humidity Monitor (ESP8266 Web Server)

This project reads **temperature** and **humidity** using a **DHT11 sensor** and displays the data on a **web server** hosted by an ESP8266.

## 📌 Features
- Reads temperature (°C) and humidity (%).
- Hosts a WiFi web server displaying live sensor data.
- Auto-refresh every 2 seconds.
- Simple UI accessible from any browser on the network.

## 🧰 Components Used
- ESP8266 NodeMCU
- DHT11 temperature & humidity sensor
- Jumper wires

## 🔌 Wiring
| DHT11 Pin | ESP8266 Pin |
|----------|--------------|
| VCC      | 3.3V         |
| GND      | GND          |
| Data     | D4 (GPIO 2)  |

## 📡 How It Works
- ESP8266 connects to WiFi.
- Sensor readings are taken.
- A local webpage is generated showing:
  - Temperature (°C)
  - Humidity (%)

## ▶️ How to Use
1. Enter your WiFi **SSID** & **Password** in the code.
2. Upload the .ino file to ESP8266.
3. Open **Serial Monitor** to find the assigned IP.
4. Enter the IP in your browser → Done!

## 📄 Source Code
File: `dht11_code_on_server.ino`

---


