#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <HCSR04.h>


UltraSonicDistanceSensor distanceSensor(D4, D3);
long distance;
const char* ssid = "Tayeb";
const char* password = "esgi12345";
#define AIO_SERVER      "192.168.43.46"
#define AIO_SERVERPORT  1883                   // on utilise le port 8883 pour le SSL
#define AIO_USERNAME    ""
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, "");
Adafruit_MQTT_Publish mqttClient = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "detect/mouvement");

void MQTT_connect() {
  int8_t ret;

  // On sort de la boucle si MQTT est connecté.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connexion à  MQTT ");

  uint8_t essaie = 3;
  while ((ret = mqtt.connect()) != 0 || essaie > 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Reconnexion à MQTT...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       essaie--;
  }
  Serial.println("MQTT est connecté !");
}

void setup_wifi() {

  // Allumer pour une connexion WIFI
  Serial.println();
  Serial.print("Connecting to ");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println(" La WiFi est connecté");
}

void setup () {
    Serial.begin(115200);  // We initialize serial connection so that we could print values from sensor.
    setup_wifi();
}

void loop () {
  distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);   
    MQTT_connect();
    char buff[5];
    sprintf(buff, "%lu", distance);
    if (!mqttClient.publish(buff)) {
      Serial.println("Envoie echoué");
    } else {
      Serial.println(" Envoie OK!");
    }
  
  Serial.println(distance);                   
}