#include <SPI.h>
#include "printf.h"
#include "RF24.h"
/* #include <SPI.h> */
/* #include <nRF24L01.h> */
/* #include <RF24.h> */


RF24 radio(7, 8); // CE, CSN

//const byte address[6] = "00001";
//const byte address[6] = "00000";
byte addresses[][6] = {"1Node", "2Node"};

void setup() {
  Serial.begin(9600);
  radio.begin();
	radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
		//Serial.println("responce found");
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}

