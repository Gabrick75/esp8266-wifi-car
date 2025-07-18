#include <ESP8266WiFi.h>
//Gabrick75
#define pinMot1A D8 //frente
#define pinMot1B D9 //trás
#define pinMot2A D10 // Esquerda
#define pinMot2B D11 // Direita

WiFiServer server(80);
int speed = 512; // Variável para armazenar a velocidade do motor (padrão 50%)
int DireitaEsquerda = 200; // Ajuste para curvas

void setup() {
  Serial.begin(115200);
  
  WiFi.begin("SSID", "PASSWORD"); //Troque o SSID e o PASSWORD pelos dados da sua rede
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Conectado à rede Wi-Fi");
  Serial.print("IP do ESP8266: ");
  Serial.println(WiFi.localIP());
  
  server.begin();

  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);

  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot1B, LOW);
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot2B, LOW);

}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  Serial.println("Cliente conectado!");
  String request = client.readStringUntil('\r');

  if (request.indexOf("/F") != -1) { // Frente
    analogWrite(pinMot1A, speed);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW); 
    Serial.println("Frente");

  } else if (request.indexOf("/B") != -1) { // Trás
    digitalWrite(pinMot1A, LOW);
    analogWrite(pinMot1B, speed);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);
    

    Serial.println("Trás");
  } else if (request.indexOf("/S") != -1) { // Parado
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);
    Serial.println("Parado");

  } else if (request.indexOf("/D") != -1) { // Direita
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    analogWrite(pinMot2A, DireitaEsquerda);
    digitalWrite(pinMot2B, LOW);
    delay(250);
    digitalWrite(pinMot2A, LOW);
    Serial.println("Direita");

  } else if (request.indexOf("/E") != -1) { // Esquerda
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    analogWrite(pinMot2B, DireitaEsquerda);
    delay(250);
    digitalWrite(pinMot2B, LOW);
    Serial.println("Esquerda");

  } else if (request.indexOf("/T") != -1) { //Test Motors
    Serial.println("testando ");
    delay(1000);

    Serial.println("desligado");
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);
    delay(1000);

    Serial.println("frente");
    analogWrite(pinMot1A, speed);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);
    delay(1000);

    Serial.println("tras"); 
    digitalWrite(pinMot1A, LOW);
    analogWrite(pinMot1B, speed);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);
    delay(1000);

    Serial.println("direita"); 
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    analogWrite(pinMot2A, speed);
    digitalWrite(pinMot2B, LOW);
    delay(1000);

    Serial.println("esquerda"); 
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    analogWrite(pinMot2B, speed);
    delay(1000);

    Serial.println("desligado");
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW); 
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);
    delay(1000);

    Serial.println("testando finalizado");


  } else if (request.indexOf("speed=") != -1) { // Ajuste de velocidade
    int start = request.indexOf("speed=") + 6;
    int end = request.indexOf(" ", start);
    String speedStr = request.substring(start, end);
    speed = speedStr.toInt();
    speed = map(speed, 0, 100, 0, 512); // Mapear a velocidade de 0-100 para 0-1023
    Serial.print("Velocidade ajustada para: ");
    Serial.println(speed);
  }
//Gabrick75
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML><html lang=\"pt-BR\">";
  s += "<head>";
  s += "    <meta charset=\"UTF-8\">";
  s += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  s += "    <title>Controle de Movimento</title>";
  s += "    <style>";
  s += "        body { font-family: Arial, sans-serif; text-align: center; background-color: #f0f0f0; }";
  s += "        button { font-size: 18px; padding: 20px; margin: 15px; width: 120px; height: 120px; background-color: #555; color: white; border: none; border-radius: 50%; box-shadow: 0px 6px #333; cursor: pointer; }";
  s += "        button:active { box-shadow: 0px 3px #333; transform: translateY(3px); }";
  s += "        input[type=range] { width: 80%; margin: 20px auto; }";
  s += "        .button-container { display: flex; justify-content: center; align-items: center; }";
  s += "        .vertical-container { display: flex; flex-direction: column; align-items: center; }";
  s += "    </style>";
  s += "    <script> function adjustSpeed(val) { var xhr = new XMLHttpRequest(); xhr.open('GET', '/?speed=' + val, true); xhr.send(); } </script>";
  s += "</head>";
  s += "<body>";
  s += "    <h1>Controle de Movimento</h1>";
  s += "    <div class=\"vertical-container\">";
  s += "        <button onclick=\"location.href='/F'\">Frente</button>";
  s += "    </div>";
  s += "    <div class=\"button-container\">";
  s += "        <button onclick=\"location.href='/E'\">Esquerda</button>";
  s += "        <button onclick=\"location.href='/S'\">STOP</button>";
  s += "        <button onclick=\"location.href='/D'\">Direita</button>";
  s += "    </div>";
  s += "    <div class=\"vertical-container\">";
  s += "        <button onclick=\"location.href='/B'\">Trás</button>";
  s += "    </div>";
  s += "    <br>";
  s += "    <label for=\"speed\">Velocidade:</label>";
  s += "    <input type=\"range\" id=\"speed\" min=\"0\" max=\"100\" value=\"50\" onchange=\"adjustSpeed(this.value)\">";
  s += "    <div class=\"button-container\">";
  s += "        <button onclick=\"location.href='/T'\">Test Motors</button>";
  s += "    </div>";
  s += "</body>";
  s += "</html>\n";

  client.print(s);
  client.stop();
  Serial.println("Cliente desconectado");
}