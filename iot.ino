#define BLYNK_TEMPLATE_ID "TMPL3NuttvkT-"
#define BLYNK_TEMPLATE_NAME "Safety Monitor"
#define BLYNK_AUTH_TOKEN "lvnkfuXVXnZ3hpa5zxLNu4CqBXMfvdsw"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TinyGPS++.h>

// -------- WiFi --------
char ssid[] = "Jash";
char pass[] = "jasmithac123";

// -------- Pins --------
#define DHTPIN 4
#define DHTTYPE DHT22
#define GAS_PIN 34
#define LDR_PIN 27   
#define RELAY_PIN 23
#define BUZZER_PIN 15
#define LED_PIN 2

// -------- Threshold --------
float tempThreshold = 30.0;
int gasThreshold = 200;

// -------- OLED --------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// -------- GPS --------
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

// -------- Objects --------
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// -------- Function --------
void sendData() {

  float temp = dht.readTemperature();
  if (isnan(temp)) return;

  int gas = analogRead(GAS_PIN);
  int ldr = digitalRead(LDR_PIN);  

  //  DEBUG LINE
  Serial.println(gas);

  // -------- Blynk --------
  if (Blynk.connected()) {
    Blynk.virtualWrite(V1, temp);
    Blynk.virtualWrite(V2, gas);
  }

  // -------- FAN CONTROL --------
  if (temp > tempThreshold) { 
    digitalWrite(RELAY_PIN, LOW); } 
    else { digitalWrite(RELAY_PIN, HIGH); 
    }

  // -------- GAS ALERT --------
  if (gas > gasThreshold) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  // -------- GPS --------
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  double lat = gps.location.isValid() ? gps.location.lat() : 0;
  double lon = gps.location.isValid() ? gps.location.lng() : 0;

  // -------- OLED --------
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temp);

  display.setCursor(0, 10);
  display.print("Gas: ");
  display.print(gas);

  display.setCursor(0, 20);
  display.print("LDR: ");
  display.print(ldr);

  display.setCursor(0, 30);
  display.print("Fan: ");
  display.print(temp > tempThreshold ? "ON" : "OFF");

  display.setCursor(0, 40);
  display.print("Lat: ");
  display.print(lat, 4);

  display.setCursor(0, 50);
  display.print("Lon: ");
  display.print(lon, 4);

  display.display();

  // -------- Serial --------
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" Gas: ");
  Serial.print(gas);
  Serial.print(" LDR: ");
  Serial.print(ldr);
  Serial.print(" Lat: ");
  Serial.print(lat);
  Serial.print(" Lon: ");
  Serial.println(lon);
}

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);   // 🔥 ADDED for digital input

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (1);
  }

  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);

  timer.setInterval(2000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}