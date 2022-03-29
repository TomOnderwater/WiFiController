/*
  Copyright (c) 2022 Tom Onderwater
  Repository: https://github.com/TomOnderwater/WiFiController

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef WiFiController_h
#define WiFiController_h
#include "Arduino.h"

#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif

#ifdef ESP32
#include <WiFi.h>
#endif
#include <ArduinoWebsockets.h>
#include <ESPAsyncWebServer.h>
//#include "config.h"
#include "web.h"

using namespace websockets;

class WiFiController
{
  public:
    WiFiController(const char* ssid, const char* pass);
    void update();
    IPAddress getIP();
    int x1();
    int x2();
    int y1();
    int y2();
    bool connected();
  private:
    int _x1, _y1, _x2, _y2;
    WebsocketsClient client;
    uint32_t lastUpdate;
    IPAddress myIP;
    void connect();
    WebsocketsServer server;
    AsyncWebServer webserver = AsyncWebServer(80);
};

#endif