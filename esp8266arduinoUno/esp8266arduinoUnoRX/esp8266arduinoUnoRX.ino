#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>

#include "SerialTransfer.h"
#include <SoftwareSerial.h>


const char* ssid     = "EXETEL B31980 2.4G"; // does not work on 5G network
const char* password = "6jqCKz5Y";


SerialTransfer myTransfer;

char arr[6];
//char data[6];
char distance[4];
//String distance;
//unsigned long distance;
//int distance;

void setup()
{
  Serial.begin(9600);
	while(!Serial){
		// serial transfer via uart needs to wait
	}
  Serial1.begin(9600);

	myTransfer.begin(Serial1);

	Serial1.write("in setup on esp8266");
	// Setup esp8266 wifi connection
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

			// Send SMS with level sensor value via ifttt server.
		WiFiClient client;

		// connect to the Maker event server
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
		//int value = 42;
		//String value2str = String(value);
		//data = data + value2str;
		String distanceData="101";
		data = data + distanceData;
		

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

}


void loop()
{
	//Serial.println("looping");
	Serial1.write("looping");
  if(myTransfer.available())
  {
    // use this variable to keep track of how many
    // bytes we've processed from the receive buffer
    uint16_t recSize = 0;

		recSize = myTransfer.rxObj(distance, recSize);
    //Serial.println(distance);
		//Serial.print("number of bytes processed from RXbuffer, recSize=");
		//Serial.println(recSize);
		//Serial.println("xfer available");
		String distanceStr = (distance);
		String distanceData = distanceStr.substring(5, 7);
		//Serial1.print("substring is=");
		//Serial.println(distanceStr);

		/* // Send SMS with level sensor value via ifttt server. */
		/* WiFiClient client; */

		/* // connect to the Maker event server */
		/* const char* apiKey = "ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp"; */
		/* String makerEvent = "tank_level"; */
		/* const char* server = "maker.ifttt.com"; */
		/* const int httpPort = 80; */
	 
		/* if (!client.connect(server, httpPort)){ */
		/* 	Serial.println("Connection failed to ifttt server"); */
		/* 	return; */
		/* } */
		/* else{ */
		/* 	Serial.println("Connected to ifttt server"); */
		/* } */
	 

		/* /// WORKS: */
		/* //char data[] = "value1=101"; */
		/* //no wrks: string data = "value1=101"; */
		/* String data = "value1=0"; */
		/* //int value = 42; */
		/* //String value2str = String(value); */
		/* //data = data + value2str; */
		/* distanceData="101"; */
		/* data = data + distanceData; */
		

		/* Serial.print("Sending data value to ifttt server, data="); */
		/* Serial.println(data); */

		/* String url = "/trigger/" + makerEvent + "/with/key/"; */
		/* url += apiKey; */
                                                                                     
		/* client.println(String("POST ") + url + " HTTP/1.1"); */
		/* client.println(String("Host: ") + server); */
		/* client.println(String("Content-Type: application/x-www-form-urlencoded")); */
		/* client.print(String("Content-Length: ")); */
		/* client.println(sizeof(data)); */
		/* client.println(); */
		/* client.println(data); */

		/* //delay(10000); */
		/* client.stop(); */

  }

}
