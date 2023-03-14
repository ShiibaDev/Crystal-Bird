// Some code fragments have been taken from an old repository: https://github.com/ShiibaDev/Fair-Sciencie/blob/master/src/main.cpp
// They are being optimized and configured for a complex operation.

// Warning, code are corrupted.
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
  String ans;

  Serial.println("Crystal Bird Initialization");
  Serial.print("Connect to wifi? [Y]es [N]o");
  while (!Serial.available());
  ans = Serial.readString();
  if (ans == "Y") {
    Serial.println("Good, starting the setup of the board");
    Serial.print("Enter SSID: ");
    while (!Serial.available());
    ssid = Serial.readString();
    Serial.print("Enter pass: ");
    while (!Serial.available());
    pass = Serial.readString();
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
    Serial.print("Initialization "); delay(2000); Serial.print("."); delay(2000); Serial.print("."); delay(2000); Serial.print(".");
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

void setup() {
  Serial.begin(9600);
  Init();
  if (ssid == "" && pass == "") {
    Serial.println("No SSID and Pass gave");
  } else {
    Serial.println("Starting. . .\n");
    Connection();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Este codigo esta en ingles, para que personas de todo el mundo puedan utilizarlo y configurarlo a su favor.