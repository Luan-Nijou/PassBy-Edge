/* library:
https://www.arduino.cc/reference/en/libraries/mfrc522/

*/
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SS_PIN 0
#define RST_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);

char nomeWifi[] = "Nome do Wifi ";
char senhaWifi[] = "Senha do Wifi";
char serverAddress[] = "https://api.tago.io/data";
char contentHeader[] = "application/json";
char tokenHeader[] = "Token!!"; //Token do dispositivo que estara conectado, estara na aba device da tago, e clique no device que voce criou, para as informações serem enviadas

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

    // Agora, envie as informações para o servidor da TagoIO
    send_info();
  }
  
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

void send_info() {
  char anyData[30];
  char postData[500]; // Aumente o tamanho para acomodar as novas variáveis
  char anyData1[30];
  char anyData2[30];
  char bAny[30];
  int statusCode = 0;

  // Inclua as novas variáveis confirmacao e acesso
  bool confirmacao = true;
  bool acesso = false;

  // Construa a string JSON com as novas variáveis
  strcpy(postData, "{\n\t\"variable\": \"id\",\n\t\"value\": ");
  strcat(postData, strID);
  strcpy(anyData, "\n\t\ },");
  strcat(postData, anyData);
  
  strcat(postData, "\n\t{\n\t\"variable\": \"confirmacao\",\n\t\"value\": ");
  strcat(postData, confirmacao ? "true" : "false");
  strcpy(anyData1, "\n\t\ },");
  strcat(postData, anyData1);
  
  strcat(postData, "\n\t{\n\t\"variable\": \"acesso\",\n\t\"value\": ");
  strcat(postData, acesso ? "true" : "false");
   strcpy(anyData2, "\n\t\ }");
  strcat(postData, anyData2);

  // Resto do código permanece o mesmo
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


