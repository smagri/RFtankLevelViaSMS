#include <ESP8266WiFi.h> 
#include "SerialTransfer.h"

SerialTransfer myTransfer;

//const char* ssid     = "Wifi Name";
//const char* password = "WiFi Password";
const char* ssid     = "EXETEL B31980 2.4G"; // does not work on 5G network
const char* password = "6jqCKz5Y";

/* const char* resource = "https://maker.ifttt.com/trigger/ESP_MotionSMS/with/key/ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp"; */
/* const char* server = "maker.ifttt.com"; */
/* const int httpPort = 80; */
const char* apiKey = "ptJbZEpqEFQaB5ZwcLwwBBAJ6KhmVoqpiGvrxModLOp";
String makerEvent = "tank_level";
const char* server = "maker.ifttt.com";
const int httpPort = 80;



void setup() {
	Serial.begin(115200);
	delay(10000); // some delay, maybe not this long needs to be there
								// println early on in setup to work
	Serial.println("in setup");
//pinMode(D5, INPUT);
	pinMode(5, INPUT);

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

	
  myTransfer.begin(Serial);

	Serial.println("end setup()");
}

void loop() 
{
	//static int i=0;
	/* int status; */
	/* if (i<4){ */
	/* 	Serial.println("looping"); */
	/* 	Serial.print("xfer status is "); */
	/* 	Serial.println(status); */
	/* } */
	/* i++; */

	
	
	if(myTransfer.available())
  {
		Serial.println("xfer available");
    int status;  
    myTransfer.rxObj(status, sizeof(status));
    if (status==1)
    {
			WiFiClient client;
			if (!client.connect(server, httpPort)){
				Serial.println("Connection failed to ifttt server");
				return;
			}
			else{
				Serial.println("Connected to ifttt server");
			}


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
			
			/* client.print(String("GET ") + resource +  */
			/* 						 " HTTP/1.1\r\n" + */
			/* 						 "Host: " + server + "\r\n" +  */
			/* 						 "Connection: close\r\n\r\n"); */
			
			/* int timeout = 5 * 10; // 5 seconds              */
      /*   while(!!!client.available() && (timeout-- > 0)) */
      /*   { */
      /*   delay(100); */
      /*   } */
      /*   while(client.available()) */
      /*   { */
      /*   Serial.write(client.read()); */
      /*   } */
      /*   client.stop(); */
      /*   delay(10000); */
    }      
  } 	

		
}  
