# WiFiController

This is a basic handler class making connecting your phone to whatever you're controlling easy. It interfaces with ArduinoWebsockets and the AsyncWebServer
to connect your smartphone. After connecting to the module, browse to 192.168.4.1 and use the javascript controller canvas to control your application.

The refresh rate is currently fixed at 30 hz

* For ESP8266 type boards such as the Wemos D1 mini you need to install the ESP8266WiFi 
* ESP32 uses the standard WiFi library. 
