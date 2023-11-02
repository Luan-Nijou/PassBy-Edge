#include <ArduinoJson.h>    // Lib to format JSON Document
#include "EspMQTTClient.h"  // Lib to comunicate MQTT from ESP
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>

//Doc: https://github.com/plapointe6/EspMQTTClient


#define SS_PIN 0
#define RST_PIN 5

char  ipJson[100];
String strID ="AAAAAAAAA";

MFRC522 rfid(SS_PIN, RST_PIN);

//MQTT and WiFi configuration
EspMQTTClient client
(
  "Euuu",                //nome da sua rede Wi-Fi
  "xvqb4249",           //senha da sua rede Wi-Fi
  "mqtt.tago.io",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  "ccdf5e6d-107a-4ee8-932f-c5902a972d1d",              // Código do Token
  "esp32",              //Nome do device
  1883                  //Porta de comunicação padrao
);

void setup()
{
  
 Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  
  Serial.println("Conectando WiFi");
  while(!client.isWifiConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");

  Serial.println("Conectando com o broker MQTT");
  while(!client.isMqttConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");
}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{}

//loop do programa
void loop()
{
   /*if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    // Nenhum cartão RFID presente ou não foi possível ler o cartão
    // Coloque aqui a sua lógica adicional, se necessário
  } else {
    // Cartão RFID detectado e lido
    for (byte i = 0; i < 4; i++) {
      strID +=
          (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
          String(rfid.uid.uidByte[i], HEX) +
          (i != 3 ? ":" : "");
    }
   }*/
   
    strID.toUpperCase();
    Serial.print("Identificador (UID) da tag: ");
    Serial.println(strID);
    


  StaticJsonDocument<300> documentoJson;
  documentoJson["variable"] = "id";
  documentoJson["value"] = strID;
  serializeJson(documentoJson, ipJson);
  Serial.println("Enviando dados de temperatura");
  Serial.println(ipJson);
  
  client.publish("topicIP", ipJson); 
  delay(5000);

  client.loop();
}
