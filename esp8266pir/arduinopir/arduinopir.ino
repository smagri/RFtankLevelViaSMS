#include "SerialTransfer.h"
#include <SoftwareSerial.h>

SerialTransfer myTransfer;
SoftwareSerial mySerial(2, 3); // RX, TX

int status;

void setup()
{
  Serial.begin(115200);

	// can replace this by
	// while (!Serial){}
	//
	// here we wait for the serial port to connect
	delay(10000);

	mySerial.begin(9600);
  myTransfer.begin(mySerial);
  pinMode(5, INPUT);

	Serial.println("TX setup finished");
}

void loop()
{
  //status = digitalRead(5);
	status = 1; // for testing
	//Serial.print("in TX status=");
	//Serial.println(status);
  myTransfer.txObj(status, sizeof(status));
  myTransfer.sendData(sizeof(status));
  //delay(100);
	delay(500);
}
