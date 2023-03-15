// Some code fragments have been taken from an old repository: https://github.com/ShiibaDev/Fair-Sciencie/blob/master/src/main.cpp
// They are being optimized and configured for a complex operation.

// Warning, code are corrupted.
#include "thingProperties.h"
#include <Arduino.h>
// WiFi Libraries
#include <SPI.h>
#include <WiFi101.h>
// Definition of every value on the board (Leds, Analogs, etc)
const int safe = 10;
const int warning = 11;
const int danger = 12;
const int LightOn = LED_BUILTIN;
// Functions (Every function made, is below this.)

// Connect to the WiFi ;)
void Restart() {
  // A fatal error occurred and we don't want to destroy the house with a explosion, so we get out of control, turning every 1 into 0, like a general shutdown.
  pinMode(danger, OUTPUT);

  bool err; err = true;

  while(err == true) {
    digitalWrite(danger, HIGH);
    delay(755);
    digitalWrite(danger, LOW);
  }
  // Below here, program the board to get out of the connection.
}

// Check if the WiFi exist or no, if it exist, then connect.
// Using the function Init(), we get the connection information. (SSID and PASSWORD.)
// Those are being stored in the board.
void Connection() {
  pinMode(safe, OUTPUT);
  pinMode(warning, OUTPUT);
  pinMode(danger, OUTPUT);
}

void setup() {
  Serial.begin(9600);
  delay(1250);
  initProperties();
  
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
    /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(LightOn, led);
}

void loop() {
  // put your main code here, to run repeatedly:
  ArduinoCloud.update();
}

void onLedChange() {
  Serial.print("Led status changed:");
  Serial.println(led);
}

// Este codigo esta en ingles, para que personas de todo el mundo puedan utilizarlo y configurarlo a su favor.