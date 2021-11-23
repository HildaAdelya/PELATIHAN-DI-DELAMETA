#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>


char ssid[] = "delameta"; // your network SSID (name)
char pass[] = "bilano1407"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,3); // RX, TX   //ESP8266 RX,TX connected to these pins

int relay1=4;
int relay2=5;
int Flame=A0;
int LDR=A1;

void setup() {
// initialize serial for debugging
Serial.begin(115200);
// initialize serial for ESP module
Serialx.begin(9600);
// initialize ESP module
WiFi.init(&Serialx);
pinMode(relay1,OUTPUT);
pinMode(Flame,INPUT);
pinMode(LDR,INPUT);

// check for the presence of the shield
if (WiFi.status() == WL_NO_SHIELD) {
Serial.println("WiFi shield not present");
// don't continue
while (true);
}

// attempt to connect to WiFi network
while ( status != WL_CONNECTED) {
Serial.print("Attempting to connect to WPA SSID: ");
Serial.println(ssid);
// Connect to WPA/WPA2 network
status = WiFi.begin(ssid, pass);
lastSend = 0;
}

// you're connected now, so print out the data
Serial.println("You're connected to the network");

//connect to MQTT server
client.setServer("broker.hivemq.com", 1883);
client.setCallback(callback);
}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "HILDA311201/lampu1") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(relay1,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(relay1,LOW);
    }
  }
  }

   if (strcmp(topic, "HILDA311201/lampu2") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(relay2,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(relay2,LOW);
    }
  }
  }
  //==============================================================
  
}

void pushdata(){
  //Ambil Data / Baca Sensor
  //int datax=random(10,100);
  int LDR= analogRead(LDR);
  int Flame= analogRead(bacaFlame);
  
  //POST TO SERIAL
  Serial.print("Sensor Flame :");Serial.print(Flame);
  Serial.print(" | Sensor LDR :"); Serial.print(LDR);
  Serial.println();
  
  //POST TO MQTT
  //client.publish("HILDA311201/datax", String(datax).c_str()); //Convert to String 
  client.publish("HILDA311201/Flame", String(Flame).c_str());
  client.publish("HILDA311201/LDR", String(LDR).c_str());
}

void loop() {
// put your main code here, to run repeatedly:
if (!client.connected()) {
reconnect();
}
if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
 }
client.loop();
}

void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
// Attempt to connect, just a name to identify the client
if (client.connect("HILDA311201")) {
Serial.println("connected");

//client.publish("outpic","Hello World");
client.subscribe("HILDA311201/lampu1",0);

} else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
}
}
}
