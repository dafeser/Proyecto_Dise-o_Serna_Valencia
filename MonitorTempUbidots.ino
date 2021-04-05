//#include "ESP8266WiFi.h"
#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-kyrS1j3BVncMsuESPD6jPmLfdKl3zP"  // Poner aqui tu TOKEN general de Ubidots
#define WIFISSID "NETLIFE-THIAGO" // Poner aqui el nombre de tu Wi-Fi
#define PASSWORD "lstdc2021" // Poner aqui la clave de tu Wi-Fi

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
}

void loop(){
    float value1 = analogRead(A0);
    client.add("temperature", value1);
    client.sendAll(true);
    delay(2000);
}
