/*
 * WiFi Controller that uses localhost to provide a javascript webpage connected through a websocket connection
 * features a dynamic double joystick controller. Values x1 and y1 represent the left joystick, x2 and y2 the right. 
 * Ideal for simple and cheap robotics applications controlled by a smartphone.
 * 
 * refresh rate: 30hz
 * value range: -128, 127, type int
 * 
 * compatible with esp8266 and esp32 architecture
 * 
 * HOWTO
 * 1) upload code
 * 2) connect to the created hotspot with your phone
 * 3) open a browser and go to 192.168.4.1
 * 
 */

#include <WiFiController.h>

WiFiController * master = NULL;

void setup() {
  Serial.begin(115200);
  //replace with your credentials
  master = new WiFiController("ssid", "password");

  Serial.print("IP: ");
  Serial.println(master->getIP());
}

void loop() {
  master->update();

  Serial.print("x1: ");
  Serial.print(master->x1());
  Serial.print('\t');
  Serial.print("y1: ");
  Serial.print(master->y1());
  Serial.print('\t');
  Serial.print("x2: ");
  Serial.print(master->x2());
  Serial.print('\t');
  Serial.print("y2: ");
  Serial.println(master->y2());
}
