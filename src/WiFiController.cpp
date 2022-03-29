#include "WiFiController.h"
#include "Arduino.h"

WiFiController::WiFiController(const char*ssid, const char* pass)
{
  WiFi.softAP(ssid, pass);
  myIP = WiFi.softAPIP();

  // HTTP handler assignment
  webserver.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", index_html_gz, sizeof(index_html_gz));
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });

  //start server
  webserver.begin();
  server.listen(82);
}
IPAddress WiFiController::getIP()
{
  return myIP;
}

int WiFiController::x1()
{
  return _x1;
}
int WiFiController::y1()
{
  return _y1;
}
int WiFiController::x2()
{
  return _x2;
}
int WiFiController::y2()
{
  return _y2;
}
void WiFiController::connect()
{
  client = server.accept();
  client.onMessage([&](WebsocketsMessage msg)
  {
    // update here
    char number[5] = {'\0', '\0', '\0', '\0', '\0'};
    int l = 0;
    int values[4] = {0, 0, 0, 0};
    int count = 0;
    for (int i = 0; i < sizeof(msg.data()); i++)
    {
      char c = msg.data()[i];
      if ((c >= 48 && c <= 57) || c == '-')
      {
        number[l] = c;
        l++;
      }
      if (c == ',' || i == sizeof(msg.data()) - 1)
      {
        sscanf(number, "%d", &values[count]);
        for (int j = 0; j < 5; j++)
        {
          number[j] = '\0';
        }
        l = 0;
        count ++;
      }
    }
    _x1 = constrain(values[0], -128, 127);
    _y1 = constrain(values[1], -128, 127);
    _x2 = constrain(values[2], -128, 127);
    _y2 = constrain(values[3], -128, 127);
  });
}
void WiFiController::update()
{
  if (!client.available()) connect();
  client.poll();
}