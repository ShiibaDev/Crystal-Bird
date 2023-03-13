// Some code fragments have been taken from an old repository: https://github.com/ShiibaDev/Fair-Sciencie/blob/master/src/main.cpp
// They are being optimized and configured for a complex operation.

/* 
Credits something: ShibaDevelopment(UwU);
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
static char ssid[256] = "";
static char pass[256] = "";

// Reset Switch
static char RT[3] = "RT";

void setup() {
  // put your setup code here, to run once:
  Init();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Already connected");
  } else {
    Connection();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // If the connection name is not working, initialize the function to restart.
}

// Security purposes, this is a test function

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

void Init() {
  Serial.begin(9600);
  Serial.println("Crystal Bird Initialization");
  Serial.print("Connect to wifi? [Y]es [N]o");
  char wifiConQ = Serial.read();
  if (wifiConQ == 'Y') {
    Serial.print("Connection SSID: ");
    if (!Serial.available()) { NULL; return;}
    delay(10000);
  } else {
    Serial.print("Installation canceled, please, to restart, give input value RT");
    while(Serial.available() > 0) {
      if(Serial.read()=='\n') {
        continue;
      } else {
        Init(); return;
      }
    }
  }
  // Check the input of RT
  if (RT == "RT") {
    Serial.println("Retrying installation procedure");
    Init();
    return;
  } else {

  }
}

// Check if the WiFi exist or no, if it exist, then connect.
// Using the function Init(), we get the connection information. (SSID and PASSWORD.)
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