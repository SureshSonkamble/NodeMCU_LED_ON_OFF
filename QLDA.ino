#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>

// WiFi parameters
const char* ssid = "PRANALI INFOTECH";
const char* password = "9373062271";
HTTPClient http; 
WiFiClient client;
int ledPin = 13; // GPIO13---D7 of NodeMCU
//host to send data
//const char* host= "http://192.168.1.16/IOT/Getstatus.php";//local
const char* host= "http://codingseekho.in/APP/IOT/Getsts.php";
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  //while (WiFi.status() != WL_CONNECTED) {
 //   delay(500);
 //   Serial.print(".");
 // }
delay(3000);
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop() {

 // http.begin(WiFiClient,host);
  http.begin(client,host);
  //http.begin(client,"http://192.168.1.16/IOT/Getstatus.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //-------------------------------
  //  if(digitalRead(ledPin)==HIGH){
  //     Serial.print("The LED is HIGH..................");
  //  }
  //  else{
  //
  //      Serial.print("The LED is LOW..................");
  //  }
    //-------------------------------
  int httpCode=http.GET();
  String payload=http.getString(); // get data from webhost continously
  Serial.print(payload);
  if(payload == "1")  // if data == 1 -> LED ON
  {
    digitalWrite(ledPin,HIGH);
    Serial.print("The LED is ON");
    }
   else if (payload == "0") // if data == 0 -> LED OFF
   {
    digitalWrite(ledPin,LOW);
     Serial.print("The LED is OFF");
    }

  delay(500);
   http.end();

}
