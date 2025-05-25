#include <WiFi.h>
#include <PubSubClient.h>

#define SENSOR_PIN 34
#define BUZZER_PIN 16

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "aqua/guard";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado ao WiFi!");
}

void reconnect() {
  if (!client.connected()) {
    Serial.print("Tentando se conectar ao MQTT...");
    String clientId = "ESP32Client-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      Serial.print("Falha, razão: ");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos.");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int sensorValue = analogRead(SENSOR_PIN);

  if (sensorValue > 2000) {
    digitalWrite(BUZZER_PIN, HIGH);
    client.publish(mqtt_topic, "Alerta de vazamento");
    delay(5000);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(100);
}
