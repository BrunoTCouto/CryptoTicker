// Screen configuration
// SDA => D2
// SCL => D1
SSD1306Wire  display(0x3c, D2, D1);

void initScreen() {
  display.init();
  display.flipScreenVertically();
}

void drawConectingToWifi() {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawXbm(34, 20, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
  display.drawString(63, 0, "Conectando Wi-Fi"); // Connecting to Wi-Fi
  display.display();
}

void drawFailedConectingToWifi(String PortalSSID,String PortalIP) {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 0, "Configurar Wi-fi");          // Config the Wi-Fi
  display.setFont(ArialMT_Plain_10);
  display.drawString(63, 15, "Para configurar o Wi-Fi,"); // to config the Wi-Fi
  display.drawString(63, 27, "conecte seu celular");      // conect your mobile phone
  display.drawString(63, 39, "na rede " + PortalSSID );   // to the network
  display.drawString(63, 51, "e acesse " + PortalIP);     // and access
  display.display();
}

void drawConectedToWifi(String NetworkSSID, String IPAddr, String MacAddr) {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 0, "Wi-Fi Conectado");       // Wi-Fi connected
  display.setFont(ArialMT_Plain_10);
  display.drawString(63, 17, "Rede: " + NetworkSSID); // Network:
  display.drawString(63, 31, "IP: " + IPAddr);        // IP:
  display.drawString(63, 45, "MAC: " + MacAddr);      // Mac:
  display.display();
}

void drawCoinPrice(String coin) {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  if(coin == "ETH"){
    display.setFont(ArialMT_Plain_16);
    display.drawString(63, 0, "ETH/BRL");
    display.setFont(ArialMT_Plain_24);
    display.drawString(63, 15, "R$ " + eth);
    display.setFont(ArialMT_Plain_10);
    display.drawString(63, 40, "Max: R$ " + ethMax);
    display.drawString(63, 50, "Min: R$ " + ethMin);
  } else {
    display.setFont(ArialMT_Plain_16);
    display.drawString(63, 0, "BTC/BRL");
    display.setFont(ArialMT_Plain_24);
    display.drawString(63, 15, "R$ " + btc);
    display.setFont(ArialMT_Plain_10);
    display.drawString(63, 40, "Max: " + btcMax);
    display.drawString(63, 50, "Min: R$ " + btcMin);
  };
  display.display();
}
