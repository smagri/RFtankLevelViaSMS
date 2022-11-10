#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>
/* #include <string> */
/* #include <cstring> */
/* #include <iostream> */

using namespace std;

//const char* ssid     = "SSID";         // The SSID (name) of the Wi-Fi network you want to connect to
//const char* password = "PASSWORD";     // The password of the Wi-Fi network
const char* ssid     = "EXETEL B31980 2.4G"; // does not work on 5G network
const char* password = "6jqCKz5Y";


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

		//Serial.println("looping");
	 WiFiClient client;
	 // connect to the Maker event server
	 /* const char* server = "maker.ifttt.com"; */
	 /* const char* resource = "https://maker.ifttt.com/trigger/ESP_MotionSMS/with/key/ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp"; */
	 /* const int httpPort = 80; */
	 /* const char* server = "maker.ifttt.com";                                */
	 /* const char* resource = "https://maker.ifttt.com/trigger/tank_level/json/with/key/ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp?value1=value1";                           */
	 /* const int httpPort = 80;                      */
	 const char* apiKey = "ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp";
	 String makerEvent = "tank_level";
	 const char* server = "maker.ifttt.com";
	 const int httpPort = 80;
	 
	 if (!client.connect(server, httpPort)){
		 Serial.println("Connection failed to ifttt server");
		 return;
	 }
	 else{
		 Serial.println("Connected to ifttt server");
	 }
	 

	 /// WORKS:
	 //char data[] = "value1=101";
	 //no wrks: string data = "value1=101";
	 String data = "value1=0";
	 int value = 42;
	 String value2str = String(value);
	 data = data + value2str;

	 Serial.print("Sending data value to ifttt server, data=");
	 Serial.println(data);

	 String url = "/trigger/" + makerEvent + "/with/key/";
	 url += apiKey;
                                                                                     
	 client.println(String("POST ") + url + " HTTP/1.1");
	 client.println(String("Host: ") + server);
	 client.println(String("Content-Type: application/x-www-form-urlencoded"));
	 client.print(String("Content-Length: "));
	 client.println(sizeof(data));
	 client.println();
	 client.println(data);

	 //delay(10000);
	 client.stop();

	 Serial.print("end setup()");
}


void loop(){

	

}
