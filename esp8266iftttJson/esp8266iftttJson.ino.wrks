#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>



//using namespace std;

//const char* ssid     = "SSID";         // The SSID (name) of the Wi-Fi network you want to connect to
//const char* password = "PASSWORD";     // The password of the Wi-Fi network
const char* ssid     = "EXETEL B31980 2.4G"; // does not work on 5G network
const char* password = "6jqCKz5Y";
//const char* ssid = "TelstraE5911B";
//const char* password = "cter32vebf";


const char* url = "https://maker.ifttt.com/trigger/tank_level/with/key/ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp";

char jsonBuffer[300];


void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10000);
  Serial.println("in setup()");
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer


	delay(2000); //bit of a delay just incase too much data is sent
  /* DynamicJsonDocument data(1024); */
  /* //JsonArray data = doc.createNestedArray("data"); */
  /* deserializeJson(data, Serial); */

  /* if (data.isNull()) */
  /* { */
  /*   return; */
  /* } */
	//WiFiClient client;
	//HTTPClient http;
	StaticJsonDocument<JSON_ARRAY_SIZE(30)> doc;

  doc["value1"] = 42;

  serializeJson(doc, jsonBuffer);

  BearSSL::WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(jsonBuffer);
	http.end();


  Serial.print("Got Code: ");
  Serial.println(httpCode);

  if (httpCode < 0)
    Serial.println(http.errorToString(httpCode));

  Serial.println("Sent:");
  Serial.println(jsonBuffer);

	delay(60000);

	 Serial.print("end setup()");
}


void loop(){

	

}
