/*
  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.1
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

const int safe = 7;
const int warning = 0;
const int danger = 6;
const int LightOn = 1;

void setup() {
  pinMode(safe, OUTPUT);
  pinMode(warning, OUTPUT);
  pinMode(danger, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
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
  pinMode(LightOn, OUTPUT);
  
  if (WiFi.status() == 0) {
    digitalWrite(safe, HIGH);
  } else {
    digitalWrite(warning, HIGH);
  }
}

void loop() {
  ArduinoCloud.update();
  digitalWrite(LightOn, led);
  digitalWrite(warning, noInternetExample);
}

/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange()  {
  Serial.print("Led status changed:");
  Serial.println(led);
}

/*
  Since NoInternetExample is READ_WRITE variable, onNoInternetExampleChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onNoInternetExampleChange()  {
  // Add your code here to act upon NoInternetExample change
  Serial.print("Example of no internet:");
  Serial.println(noInternetExample);
}