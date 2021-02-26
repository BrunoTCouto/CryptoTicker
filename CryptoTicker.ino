
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












































//void printData(String data)
//{
//  setTextXY(2,0);
//  displayString("R$ ");
//
//  setTextXY(2,2);
//  char __data[sizeof(data)];
//  data.toCharArray(__data, sizeof(__data));
//  displayString(__data);
//}
//
//void sendData(unsigned char data)
//{
//  Wire.beginTransmission(I2C_ADDRESS);  // begin I2C transmission
//  Wire.write(CMD_MODE_DATA);            // set mode: data
//  Wire.write(data);
//  Wire.endTransmission();               // stop I2C transmission
//}
//
//void sendCommand(unsigned char command)
//{
//  Wire.beginTransmission(I2C_ADDRESS);  // begin I2C communication
//  Wire.write(CMD_MODE_COMMAND);         // set mode: command
//  Wire.write(command);
//  Wire.endTransmission();               // End I2C communication
//}
//
//void displayInit()
//{
//  sendCommand(CMD_DISPLAY_OFF); //DISPLAYOFF
//  sendCommand(0x8D);            //CHARGEPUMP Charge pump setting
//  sendCommand(0x14);            //CHARGEPUMP Charge pump enable
//  sendCommand(0xA1);            //SEGREMAP   Mirror screen horizontally (A0)
//  sendCommand(0xC8);            //COMSCANDEC Rotate screen vertically (C0)
//}
//
//void setTextXY(unsigned char row, unsigned char col)
//{
//    sendCommand(0xB0 + row);                //set page address
//    sendCommand(0x00 + (8*col & 0x0F));     //set column lower address
//    sendCommand(0x10 + ((8*col>>4)&0x0F));  //set column higher address
//}
//
//void displayString(const char *str)
//{
//    unsigned char i=0, j=0, c=0;
//    while(str[i])
//    {
//      c = str[i++];
//      if(c < 32 || c > 127) //Ignore non-printable ASCII characters. This can be modified for multilingual font.
//      {
//        c=' '; //Space
//      }
//      for(j=0;j<8;j++)
//      {
//         //read bytes from code memory
//         sendData(pgm_read_byte(&BasicFont[c-32][j])); //font array starts at 0, ASCII starts at 32. Hence the translation
//      }
//    }
//}
//
//void displayClear()
//{
//  unsigned char i=0, j=0;
//  sendCommand(CMD_DISPLAY_OFF);     //display off
//  for(j=0;j<8;j++)
//  {        
//    setTextXY(j,0);                                                                            
//    {   
//      for(i=0;i<16;i++)  //clear all columns
//      {   
//        displayString((const char*)" ");         
//      }   
//    }   
//  }
//  sendCommand(CMD_DISPLAY_ON);     //display on
//  setTextXY(0,0);   
//}
