#include "SerialTransfer.h"
#include "SoftwareSerial.h"

SerialTransfer myTransfer;
SoftwareSerial Serial1(2, 3);

char arr[] = "hello world";


void setup()
{
  Serial.begin(9600);
	while(!Serial){
		// serial transfer via uart needs to wait
	}
	Serial1.begin(9600);
  
	myTransfer.begin(Serial1);

}


void loop()
{
	static int loop_times = 0;

	if (loop_times<5){
		// use this variable to keep track of how many
		// bytes we're stuffing in the transmit buffer
		uint16_t sendSize = 0;

		unsigned long distance = 101;
		//char data[] = "101";
		sendSize = myTransfer.txObj(distance, sendSize);
		Serial.print("number of bytes processed from TXbuffer, recSise=");

		// Send buffer
		myTransfer.sendData(sendSize);
		delay(500);
		loop_times++;
	}
	//Serial.println("tx is done");
}
