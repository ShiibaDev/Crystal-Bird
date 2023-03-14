// Some code fragments have been taken from an old repository: https://github.com/ShiibaDev/Fair-Sciencie/blob/master/src/main.cpp
// They are being optimized and configured for a complex operation.

// Este codigo esta en ingles, para que personas de todo el mundo puedan utilizarlo y configurarlo a su favor.

/* 
Credits something: ShibaDevelopment(UwU);
*/
#include <Arduino.h>
// WiFi Libraries
#include <SPI.h>
#include <WiFi101.h>
// Definition of every value on the board (Leds, Analogs, etc)
const int safe = 10;
const int warning = 11;
const int danger = 12;

// Definitions of input
String ssid = "";
String pass = "";

// Reset Switch
String RT = "";

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
  String wifiConQ;
  while (Serial.available() > 0) {
    wifiConQ = Serial.readString();
  }
  if (wifiConQ == "Y") {
    Serial.print("Connection SSID: ");
    while (Serial.available() > 0) {
      ssid = Serial.readString();
    }
    Serial.println();
    Serial.print("Connection PASS: ");
    while (Serial.available() > 0) {
      pass = Serial.readString();
    }
    Serial.println();
  } else if (wifiConQ == "N") {
    Serial.println("Installation canceled, please, to restart.\n\n Give input value RT");
  } else {
    Serial.println("Invalid input, returning. . .");
    Init(); return;
  }
  // Check the input of RT
  if (RT == "RT") {
    Serial.println("Retrying installation procedure");
    Init();
    return;
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

    // Connect, using `WiFi.begin();`
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

void setup()
{
  // put your setup code here, to run once:
  Init();
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Already connected");
  }
  else
  {
    Connection();
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}