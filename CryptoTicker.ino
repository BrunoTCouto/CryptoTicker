
#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>       // Benoit Blanchon 5.13.5
#include <DNSServer.h>         // tzapu 2.0.3-alpha
#include <ESP8266WebServer.h>  // tzapu 2.0.3-alpha
#include <WiFiManager.h>       // tzapu 2.0.3-alpha
#include "SSD1306Wire.h"       // Adafruit SSD1306 2.4.3

#include <Wire.h>

WiFiClientSecure client;

String btc;
String btcMax;
String btcMin;
String eth;
String ethMax;
String ethMin;

#include "images.h"
#include "screen.h"
#include "wifi.h"
#include "http.h"

void drawConectingToWifi();
void drawFailedConectingToWifi(String PortalSSID, String PortalIP);
void drawConectedToWifi(String NetworkSSID, String IPAddr, String MacAddr);
void drawCoinPrice(String coin);
void getData(String coin);
void configModeCallback(WiFiManager *myWiFiManager);

void setup() {
  Serial.begin(115200);

  display.init();
  display.flipScreenVertically();
  
  drawConectingToWifi();
  WiFiManager wifiManager;
//  wifiManager.resetSettings();
  wifiManager.setAPCallback(configModeCallback);
//  wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
  wifiManager.autoConnect("CryptoTicker");

  String WifiSSID = WiFi.SSID();
  String WifiIP = WiFi.localIP().toString(); 
  String WifiMac = WiFi.macAddress(); 
  drawConectedToWifi(WifiSSID, WifiIP, WifiMac); 
  client.setInsecure();
  Wire.begin();  
  
  delay(5000);
}

void loop(){
  getData("BTC");
  drawCoinPrice("BTC");
  delay(5000);
  getData("ETH");
  drawCoinPrice("ETH");
  delay(5000);
}
