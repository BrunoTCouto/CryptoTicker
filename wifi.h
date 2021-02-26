void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  String PortalIP = WiFi.softAPIP().toString();
  String PortalSSID = String(myWiFiManager->getConfigPortalSSID());
  drawFailedConectingToWifi(PortalSSID, PortalIP);

  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
}
