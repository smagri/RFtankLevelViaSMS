#include "SerialTransfer.h"
#include "SoftwareSerial.h"

SerialTransfer myTransfer;
SoftwareSerial Serial1(2, 3);

struct STRUCT {
  char z;
  float y;
} testStruct;

char arr[] = "hello world";


void setup()
{
  Serial.begin(9600);
	//while(!Serial){}
	Serial1.begin(9600);
  //myTransfer.begin(Serial1);
	myTransfer.begin(Serial1);

  testStruct.z = '$';
  testStruct.y = 4.5;
}


void loop()
{
  // use this variable to keep track of how many
  // bytes we're stuffing in the transmit buffer
  uint16_t sendSize = 0;

  ///////////////////////////////////////// Stuff buffer with struct
  //sendSize = myTransfer.txObj(testStruct, sendSize);
	//int data = 101; !wrks
  ///////////////////////////////////////// Stuff buffer with array
  //sendSize = myTransfer.txObj(arr, sendSize);
	char data[] = "101";
	sendSize = myTransfer.txObj(data, sendSize);

  ///////////////////////////////////////// Send buffer
  myTransfer.sendData(sendSize);
  delay(500);
	Serial.println("tx is done");
}
