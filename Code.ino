#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

char nomeWifi[] = "iPhone Airton";
char senhaWifi[] = "2153818aa";
char serverAddress[] = "https://api.tago.io/data";
char contentHeader[] = "application/json";
char tokenHeader[] = "Token!!!!";
float temperatura = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  init_wifi();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    // Nenhum cartão RFID presente ou não foi possível ler o cartão
    // Coloque aqui a sua lógica adicional, se necessário
  } else {
    // Cartão RFID detectado e lido
    String strID = "";
    for (byte i = 0; i < 4; i++) {
      strID +=
          (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
          String(rfid.uid.uidByte[i], HEX) +
          (i != 3 ? ":" : "");
    }
    strID.toUpperCase();
    Serial.print("Identificador (UID) da tag: ");
    Serial.println(strID);

    // Agora, envie a temperatura para o servidor TagoIO
    send_temperatura();
  }

  // Incrementar temperatura simulada
  temperatura++;
  delay(5000);
}

void init_wifi() {
  Serial.println("Conectando WiFi");
  Serial.print("Wifi: ");
  Serial.println(nomeWifi);
  WiFi.begin(nomeWifi, senhaWifi);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  Serial.println("WiFi Conectado");
  Serial.print("Meu IP eh: ");
  Serial.println(WiFi.localIP());
}

void send_temperatura() {
  char anyData[30];
  char postData[300];
  char anyData1[30];
  char bAny[30];
  int statusCode = 0;
  strcpy(postData, "{\n\t\"variable\": \"temperature\",\n\t\"value\": ");
  dtostrf(temperatura, 6, 2, anyData);
  strncat(postData, anyData, 100);
  strcpy(anyData1, ",\n\t\"unit\": \"C\"\n\t}\n");
  strncat(postData, anyData1, 100);
  Serial.println(postData);
  HTTPClient client;
  client.begin(serverAddress);
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);
  statusCode = client.POST(postData);
  delay(2000);
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.println("End of POST to TagoIO");
  Serial.println();
}

