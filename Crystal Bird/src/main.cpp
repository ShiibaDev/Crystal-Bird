// Some code fragments have been taken from an old repository: https://github.com/ShiibaDev/Fair-Sciencie/blob/master/src/main.cpp
// They are being optimized and configured for a complex operation.


// this is the only and last project of IoT I am gonna work, the next projects gonna focus only web development. (ShibaDev)

// Warning, code are corrupted.
#include "thingProperties.h"
#include <Arduino.h>

// Every important value is on thingProperties.h

const int safe = 10;
const int warning = 11;
const int danger = 12;
const int LightOn = 13;

// Analogs

// Functions (Every function made, is below this.)

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
  
  Serial.println("**////////////////**");
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  Serial.println("**////////////////**");
  pinMode(LightOn, led);
}

void loop() {
  // put your main code here, to run repeatedly:
  Connect();
}

void Connect() {
  pinMode(warning, OUTPUT);
  ArduinoCloud.update();
  while (ArduinoCloud.connected() == 0) {
    Serial.println("Waiting Connection, sorry :(");
    digitalWrite(warning, HIGH);
    delay (1000);
    digitalWrite(warning, LOW);
    if (ArduinoCloud.connected() == 1) {
      break;
      digitalWrite(warning, LOW);
    }
  }
}

void Initialize() {
  Serial.print("Board Status");
  Serial.println(led);

  if (led == 0) {
    // Insert code to turn offline the board.
    Serial.print("Board offline");
  }
}

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
  errMessage();
  Serial.println(" <- This the error message.");
}

void errMessage() {
  setDebugMessageLevel(1);
  ArduinoCloud.printDebugInfo();
}

void lightTurnOnOff() {
  Serial.print("Light status");
  Serial.println(roomLight);
}
// Este codigo esta en ingles, para que personas de todo el mundo puedan utilizarlo y configurarlo a su favor.