#include <SPI.h>
#include <WiFiNINA.h>

const char* ssid     = "EXETEL B31980 2.4G"; // does not work on 5G network
const char* password = "6jqCKz5Y";

const char* resource = "https://maker.ifttt.com/trigger/ESP_MotionSMS/with/key/ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp";
const char* server_ifttt = "maker.ifttt.com";
const int httpPort = 80;
//WiFiServer server(23);
int status = WL_IDLE_STATUS;
WiFiServer server(80);


void setup(){

	Serial.begin(9600);
	while(!Serial){
		; // wait for serial port to connect. Needed for uart
	}

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, password);
    delay(10000);
  }
	server.begin();

  printWifiStatus(); // You're connected now, so print out the status.

	WiFiClient client;
	if (!client.connect(server_ifttt, httpPort)){
		Serial.println("Connection failed to ifttt server");
		return;
	}
	else{
		//Serial.println("Connected to ifttt server");
	}
	
	client.print(String("GET ") + resource + 
							 " HTTP/1.1\r\n" +
							 "Host: " + server_ifttt + "\r\n" + 
							 "Connection: close\r\n\r\n");

	//client.stop();
	//Serial.println("client disconnected")
	
}

void loop(){
	
}






void printWifiStatus(){

  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  //server.write(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  
  // display wifi shield firmware version, version < 1.1 requres a
  // firmware update of wifi shield.
  Serial.print("Firmware Version(version < 1.1.0 requires firmware upgrade):");
  Serial.println(WiFi.firmwareVersion());
}
