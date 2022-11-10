#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>



//#define DEBUG

//const char* ssid     = "SSID";  // The SSID (name) of the Wi-Fi
																// network you want to connect to
//const char* password = "PASSWORD"; // The password of the Wi-Fi network
const char* ssid     = "EXETEL B31980 2.4G"; // does not work on 5G network
const char* password = "6jqCKz5Y";
//const char* ssid = "TelstraE5911B";
//const char* password = "cter32vebf";


const char* url = "https://maker.ifttt.com/trigger/tank_level/with/key/ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp";

// Dre's eg
//char jsonBuffer[300];


void setup() {
  Serial.begin(9600); // Start the Serial communication to send
											// messages to the computer
  while(!Serial){
		// serial transfer via uart need to wait
	}
	delay(5000); // needs some extra delay for some reason
//  Serial.println("in setup()");
  
  WiFi.begin(ssid, password);             // Connect to the network
#ifdef DEBUG
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");
#endif
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
#ifdef DEBUG
    Serial.print(++i); Serial.print(' ');
#endif
  }

#ifdef DEBUG
  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); // Send the IP address of the
																	// ESP8266 to the computer
#endif

	delay(2000); //bit of a delay just incase too much data is sent
	// DRE's eg
	/* StaticJsonDocument<JSON_ARRAY_SIZE(30)> doc; */
  /* doc["value1"] = 42; */
  /* serializeJson(doc, jsonBuffer); */

//		Serial.println("end setup()");
}


void loop(){

	if (Serial.available()){
		String distanceStr = Serial.readString();
		//distanceStr.trim(); // remove any \r\n at end of string
#ifdef DEBUG
		Serial.print("value read is: ");
		Serial.println(distanceStr);
#endif
		// Prepare JSON document 
		DynamicJsonDocument doc(2048);
		//doc["value1"] = 101;
		doc["value1"] = distanceStr;
		String json;
		// Serialise JSON document
		serializeJson(doc, json);

		// DRE's eg
		BearSSL::WiFiClientSecure client; // HTTPS secure HTTP request
		client.setInsecure();

		// no wrks:
		// WiFiClient client;
		//WiFiClientSecure client; // for HTTPS
		HTTPClient http;

		// Send request
		http.begin(client, url);
		http.addHeader("Content-Type", "application/json");
		int httpCode = http.POST(json);
		http.end();

#ifdef DEBUG
		Serial.print("Got Code: ");
		Serial.println(httpCode);

		if (httpCode < 0)
			Serial.println(http.errorToString(httpCode));

		Serial.println("Sent:");
		Serial.println(json);
#endif
		delay(60000);
	}

}
