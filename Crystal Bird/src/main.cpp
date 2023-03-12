// Some code fragments have been taken from an old repository: https://github.com/ShiibaDev/Fair-Sciencie/blob/master/src/main.cpp
// They are being optimized and configured for a complex operation.

/* 
ShibaDvelopment(UwU);
*/

#include <Arduino.h>
// WiFi Libraries
#include <SPI.h>
#include <WiFi101.h>

using namespace std;
// Definition of every value on the board (Leds, Analogs, etc)
const int safe = 10;
const int warning = 11;
const int danger = 12;

// Definitions of input
String ssid = "";
String pass = "";

// Reset Switch
String RT = "";

// Security purposes, this is a test function

// Functions (Every function made, is below this.)
// Connect to the WiFi ;)
void Init() {
  // put your setup code here, to run once:
  Serial.println("Crystal Bird Initialization");
  Serial.print("Connect to wifi? [Y]es [N]o");
  char wifiConQ = Serial.read();
  if (wifiConQ == 'Y') {
    Serial.print("Connection SSID: ");
    ssid = Serial.readString();
    pass = Serial.readString();
    Serial.println();
  } else {
    Serial.print("Installation canceled, please, to restart, give input value RT");
    RT = Serial.readString();
  }
  // Check the input of RT
  if (RT == "RT") {
    Serial.println("Retrying installation procedure");
    Init();
    return;
  } else {
    const int INITIAL_DELAY_TIME = 5000;
    int RetriesCount = 0;
    int delaytime = INITIAL_DELAY_TIME;

    while (RT != "RT")
    {
      Serial.print("Retrying in... ");
      Serial.print(delaytime);
      delay(delaytime); delaytime *= 2;

      if (delaytime >= 30000) {
        delaytime = 30000;
      }
      RetriesCount++;

      if (Serial.available() > 0) {
        RT = Serial.readString();
      }
    }

    if (RT == "RT") {
      Serial.println("Installation on process, retrying protocol has been started.");
      Init();
      return;
    }
  }
}

// Check WiFi connection, then connect it.
// Using the function of above, we get the connection information. (SSID and PASSWORD.)
// Those are being stored in the board.
void Connection() {
  pinMode(safe, OUTPUT);
  pinMode(warning, OUTPUT);
  pinMode(danger, OUTPUT);

  for (int j = 0; j < 10; j++) {
    Serial.print("Initialization "); delay(1000); Serial.print("."); delay(1000); Serial.print("."); delay(1000); Serial.print(".");
    digitalWrite(warning, HIGH);
    digitalWrite(danger, HIGH);

    Serial.print(ssid);
    Serial.print(" <== Connection name");
    WiFi.begin(ssid, pass);

    if (WiFi.status() == WL_CONNECTED) {
      break;
      digitalWrite(warning, LOW);
      digitalWrite(danger, LOW);
    }
  }

  // Investigation on process.
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
  Init();
}

void loop() {
  // put your main code here, to run repeatedly:
}