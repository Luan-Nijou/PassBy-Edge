#include <ArduinoJson.h>    // Lib to format JSON Document
#include "EspMQTTClient.h"  // Lib to comunicate MQTT from ESP
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>

//Doc: https://github.com/plapointe6/EspMQTTClient

#define SS_PIN 0
#define RST_PIN 5

char  idJson[100];
char  PermJson[100];
char  PagJson[100];

float conta = 10;
float pagar = 10;

float valorPagar;
float valorPerm;

String strID ="AAAAAAAAC";
String strID2 ="AAAAAAAAC";


//MFRC522 rfid(SS_PIN, RST_PIN);

//MQTT and WiFi configuration
EspMQTTClient client
(
  "Wokwi-GUEST",                //nome da sua rede Wi-Fi
  "",           //senha da sua rede Wi-Fi
  "mqtt.tago.io",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  "ccdf5e6d-107a-4ee8-932f-c5902a972d1d",              // Código do Token
  "esp32",              //Nome do device
  1883                  //Porta de comunicação padrao
);

void setup()
{
  
   Serial.begin(9600);
  //SPI.begin();
 // rfid.PCD_Init();
  
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
  
   if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    
  } else {
    // Cartão RFID detectado e lido
    for (byte i = 0; i < 4; i++) {
      strID +=
          (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
          String(rfid.uid.uidByte[i], HEX) +
          (i != 3 ? ":" : "");
    }
   }
   

    strID.toUpperCase();
    Serial.print("Identificador (UID) da tag: ");
    Serial.println(strID);
    
  if(strID == strID2 ){
    valorPerm = 1;
  }else{
    valorPerm = 0;
  }

  if(conta>=pagar){
    valorPagar = 1;
  }else{
    valorPagar = 0;
  }



  StaticJsonDocument<300> documentoJson;
  documentoJson["variable"] = "id";
  documentoJson["value"] = strID;
  serializeJson(documentoJson, idJson);

  documentoJson["variable"] = "permissao";
  documentoJson["value"] = valorPerm;
  serializeJson(documentoJson, PermJson);

  documentoJson["variable"] = "pagamento";
  documentoJson["value"] = valorPagar;
  serializeJson(documentoJson, PagJson);

  Serial.println("Enviando os dados");
  Serial.println(idJson);
  Serial.println(PermJson);
  Serial.println(PagJson);
  
  client.publish("topicIP", idJson); 
  client.publish("topicIP", PermJson); 
  client.publish("topicIP", PagJson); 
  delay(5000);

  client.loop();
}
