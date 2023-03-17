// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include "Secret.h"
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char ssid[] = SECRET_SSID;    // Network SSID (name)
const char pass[] = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)

void onLedChange();

bool led;
bool err;

void initProperties(){
   ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
   ArduinoCloud.addProperty(led, READ, ON_CHANGE, Restart);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(ssid, pass);