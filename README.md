<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/3ec07d48-7f05-4ed2-bfe8-0bbec960e208" /><img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/ded80255-10d6-4818-8885-0623303e6427" /> 🌍 Integrated IoT-Based Environment Monitoring and Emergency Alert System

 📌 Project Overview

This project is an IoT-based safety monitoring system built using ESP32. It continuously monitors environmental parameters such as temperature, gas levels, and light intensity. In case of abnormal conditions (like high temperature or gas leakage), the system automatically triggers alerts using a buzzer and LED, and also controls a relay (fan).

Additionally, the system sends real-time data to the Blynk cloud and displays information on an OLED screen. A GPS module is also integrated to provide live location tracking for emergency situations.

 🎯 Objectives

* Monitor environmental conditions in real time
* Detect hazardous situations like gas leakage
* Provide instant alerts using buzzer and LED
* Enable remote monitoring through Blynk IoT platform
* Display data locally using OLED
* Track live location using GPS for emergency response


🛠️ Hardware Components

* ESP32 Microcontroller
* DHT22 Temperature Sensor
* Gas Sensor (MQ series)
* LDR (Light Dependent Resistor)
* OLED Display (SSD1306)
* GPS Module (Neo-6M or similar)
* Relay Module (for fan control)
* Buzzer
* LED


💻 Software & Libraries Used

* Arduino IDE
* Embedded C / Arduino Programming
* Blynk IoT Platform

 Libraries:

* WiFi.h
* BlynkSimpleEsp32.h
* DHT.h
* Wire.h
* Adafruit_GFX.h
* Adafruit_SSD1306.h
* TinyGPS++.h


⚙️ System Working

1. The ESP32 reads temperature from the DHT22 sensor.
2. Gas sensor detects gas concentration levels.
3. LDR detects light conditions (day/night).
4. If temperature exceeds the threshold, the relay activates the fan.
5. If gas level exceeds the threshold, buzzer and LED turn ON.
6. GPS module continuously updates location coordinates.
7. All sensor data is:

   * Sent to Blynk cloud for remote monitoring
   * Displayed on OLED screen
   * Printed on Serial Monitor for debugging


 📊 Features

* 🌡️ Real-time temperature monitoring
* 💨 Gas leakage detection and alert system
* 💡 Light sensing using LDR
* 📍 GPS-based location tracking
* 📲 Remote monitoring via Blynk app
* 🔔 Automatic buzzer and LED alerts
* 🌀 Smart fan control using relay
* 🖥️ OLED display output


 🔌 Pin Configuration

| Component  | Pin         |
| ---------- | ----------- |
| DHT22      | GPIO 4      |
| Gas Sensor | GPIO 34     |
| LDR        | GPIO 27     |
| Relay      | GPIO 23     |
| Buzzer     | GPIO 15     |
| LED        | GPIO 2      |
| GPS RX/TX  | GPIO 16, 17 |



 🧠 Logic & Thresholds

* Temperature Threshold: 30°C
* Gas Threshold: 200
* Fan turns ON when temperature exceeds threshold
* Buzzer & LED activate when gas exceeds threshold



🚀 How to Run the Project

1. Install Arduino IDE
2. Install all required libraries
3. Connect ESP32 to your system
4. Update WiFi credentials and Blynk token
5. Upload the code to ESP32
6. Open Serial Monitor to view output
7. Monitor data using Blynk app

 
 📈 Future Enhancements

* Add mobile notification alerts
* Integrate cloud data storage (Firebase)
* Add smoke/fire detection sensor
* Develop a web dashboard
* Improve power efficiency using sleep modes


  Author

Jasmitha C

🔗 Repository Link
https://github.com/Jasmithac-123/Intergerated-iot-based-system-for-environment-monitoring-and-emergency-alrt/tree/main

https://github.com/username/repository-name
