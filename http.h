void getData(String coin) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Declare an object of class HTTPClient

    http.begin(client,"https://api.bitcointrade.com.br/v3/public/BRL" + coin + "/ticker");  //Specify request destination
    int httpCode = http.GET();  //Send the request
  
    Serial.println(httpCode);
    if (httpCode > 0) {  //Check the returning code
  
      String payload = http.getString();  //Get the request response payload
      Serial.println(payload);  //Print the response payload
      String json_str = String(payload);
      
      Serial.println(json_str);
      
      DynamicJsonBuffer jBuffer;
      JsonObject& root = jBuffer.parseObject(json_str);
    
      Serial.println("JsonObject: ");
      root.prettyPrintTo(Serial);
      Serial.println();
    
      JsonObject& requestData = root["data"];
      String tmp = requestData["last"];
      String tmp2 = requestData["low"];
      String tmp3 = requestData["high"];
      if(coin == "ETH"){
        eth = tmp.toInt();
        ethMin = tmp2.toInt();
        ethMax = tmp3.toInt();
        Serial.print(coin + " (BRL): R$ " + eth.toInt());
      } else {
        Serial.print(coin + " (BRL): R$ " + btc.toInt());
        btc = tmp.toInt();
        btcMin = tmp2.toInt();
        btcMax = tmp3.toInt(); 
      };
    }
  
    http.end();  //Close connection
  }
}
