#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Définition des Pins (Nouveau Montage avec 4 Potentiomètres)
#define POT_TEMP1 34       // Température Moteur 1
#define POT_TEMP2 35       // Température Moteur 2
#define POT_VIB1  32       // Vibrations Moteur 1
#define POT_VIB2  33       // Vibrations Moteur 2

#define DHTPIN_PRESS1 2    // Pression Moteur 1
#define DHTPIN_PRESS2 16   // Pression Moteur 2
#define DHTTYPE DHT22

// Initialisation des DHT
DHT dht1(DHTPIN_PRESS1, DHTTYPE);
DHT dht2(DHTPIN_PRESS2, DHTTYPE);

// Configuration WiFi et MQTT
const char* ssid = "Wokwi-GUEST";
const char* mqtt_server = "broker.hivemq.com";
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("--- SYSTÈME COCKPIT AVION : PRÊT ---");

  dht1.begin(); 
  dht2.begin();

  // Connexion WiFi
  WiFi.begin(ssid, "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connecté !");
  
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    client.connect("Avion_ESP32_Simulation_Pro");
  }
  client.loop();

  // --- TRAITEMENT MOTEUR 1 (GAUCHE) ---
  // Température : 0 à 1000 °C
  float t1 = map(analogRead(POT_TEMP1), 0, 4095, 0, 1000);
  // Vibrations : 0 à 100 mm/s (Plus facile à contrôler que le MPU)
  float v1 = map(analogRead(POT_VIB1), 0, 4095, 0, 100);
  float p1 = dht1.readHumidity(); // Pression Huile

  String json1 = "{\"temp\":" + String(t1) + ",\"press\":" + String(p1) + ",\"vib\":" + String(v1) + "}";
  client.publish("avion/moteur1/data", json1.c_str());
  Serial.print("MOTEUR 1 > "); Serial.println(json1);

  // --- TRAITEMENT MOTEUR 2 (DROIT) ---
  float t2 = map(analogRead(POT_TEMP2), 0, 4095, 0, 1000);
  float v2 = map(analogRead(POT_VIB2), 0, 4095, 0, 100);
  float p2 = dht2.readHumidity();

  String json2 = "{\"temp\":" + String(t2) + ",\"press\":" + String(p2) + ",\"vib\":" + String(v2) + "}";
  client.publish("avion/moteur2/data", json2.c_str());
  Serial.print("MOTEUR 2 > "); Serial.println(json2);

  delay(200); // Mise à jour rapide pour Node-RED
}