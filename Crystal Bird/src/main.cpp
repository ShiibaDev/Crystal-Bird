#include <Arduino.h>
// WiFi Libraries
#include <SPI.h>
#include <WiFi101.h>
// Definition of every value on the board (Leds, Analogs, etc)
const int safe = 10;
const int warning = 11;
const int danger = 12;

// Security purposes, this is a test function

// Functions (Every function made, is below this.)
void Init() {
  // put your setup code here, to run once:
  Serial.println("Crystal Bird Initialization");
  Serial.print("Connect to wifi? [Y]es [N]o");
  char wifiConQ = Serial.read();
  if (wifiConQ == 'Y') {
    Serial.print("Connection SSID: ");
    std:String ssid = Serial.readString();
  }
}

// Connect to the Wifi and check it.
void Connection() {
  if (WiFi.status() == WL_CONNECTED) {
    pinMode(safe, OUTPUT);

    for (int i = 0; i < 10; i++) {
      digitalWrite(safe, LOW);
      delay(850);
      digitalWrite(safe, HIGH);
    }
  } else {
    pinMode(warning, OUTPUT);

    digitalWrite(warning, HIGH);
    // If error fixed, turn the warning led off.
    if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(warning, LOW);
    }
  }
}

void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
}