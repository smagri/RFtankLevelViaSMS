#include <string.h>
//#include <cstring.h>

#include "SerialTransfer.h"
#include "SoftwareSerial.h"

using namespace std;

SerialTransfer myTransfer;
SoftwareSerial Serial1(2, 3); // RX,TX

char arr[] = "hello world";


void setup()
{
  Serial.begin(9600);
	while(!Serial){
		// serial transfer via uart needs to wait
	}
	Serial1.begin(9600);
	Serial1.println("setup begins on Serial1");
	
	myTransfer.begin(Serial1);
	

}


void loop()
{
	static int loop_times = 0;

	//if (loop_times<5){
		// use this variable to keep track of how many
		// bytes we're stuffing in the transmit buffer
		uint16_t sendSize = 0;

		// Can only send char array not type String and integers are sent
		// as chars anyway.
		unsigned int distanceInt = 101;
		String distanceStr = String(distanceInt); // from arduino classes
		char distance[4];
		distanceStr.toCharArray(distance, sizeof(distance)); // from arduino classes
		
		sendSize = myTransfer.txObj(distance, sendSize);
		Serial.print("number of bytes processed from TXbuffer, sendSize=");
		Serial.println(sendSize);
		Serial.print("sent data distance is=");
		Serial.println(distance);

		// Send buffer
		myTransfer.sendData(sendSize);
		delay(500);
		//loop_times++;
		//}
	//Serial.println("tx is done");
}
