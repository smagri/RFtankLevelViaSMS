#include <SPI.h>
#include "printf.h"
#include "RF24.h"
/* #include <SPI.h> */
/* #include <nRF24L01.h> */
/* #include <RF24.h> */




RF24 radio(7, 8); // CE, CSN

//const byte address[6] = "00001";
byte addresses[][6] = {"1Node", "2Node"};

void setup() {
  radio.begin();
  radio.openWritingPipe(addresses[1]);
	radio.openReadingPipe(1, addresses[0]);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}

