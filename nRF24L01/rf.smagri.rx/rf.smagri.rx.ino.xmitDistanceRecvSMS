/*
 * See documentation at https://nRF24.github.io/RF24
 * See License information at root directory of this library
 * Author: Brendan Doherty (2bndy5)
 */

/**
 * A simple example of sending data from 1 nRF24L01 transceiver to another.
 *
 * This example was written to be used on 2 devices acting as "nodes".
 * Use the Serial Monitor to change each node's behavior.
 */
#include <SPI.h>
#include "printf.h"
#include "RF24.h"

//#define DEBUG

// instantiate an object for the nRF24L01 transceiver
RF24 radio(7, 8);  // using pin 7 for the CE pin, and pin 8 for the CSN pin

// Let these addresses be used for the pair
uint8_t address[][6] = { "1Node", "2Node" };
// It is very helpful to think of an address as a path instead of as
// an identifying device destination

// to use different addresses on a pair of radios, we need a variable to
// uniquely identify which address this radio will use to transmit
///bool radioNumber = 1;  // 0 uses address[0] to transmit, 1 uses address[1] to transmit
bool radioNumber = 0; // use radioNumber 0 to RX, expects radioNumber 1 as TX

// Used to control whether this node is sending or receiving
bool role = false;  // true = TX role, false = RX role

// For this example, we'll be using a payload containing
// a single float number that will be incremented
// on every successful transmission
//float payload = 0.0;
//String payload = "hello world";
unsigned long payload = 0.0;

void setup() {

//	delay(5);
  //Serial.begin(115200);
	Serial.begin(9600);
  while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
  }

  // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
#ifdef DEBUG
    Serial.println(F("radio hardware is not responding!!"));
#endif
    while (1) {}  // hold in infinite loop
  }


  // Set the PA Level low to try preventing power supply related problems
  // because these examples are likely run with nodes in close proximity to
  // each other.
  radio.setPALevel(RF24_PA_LOW);  // RF24_PA_MAX is default.
//  radio.setPALevel(RF24_PA_MAX);  // RF24_PA_MAX is default.

  // save on transmission time by setting the radio to only transmit the
  // number of bytes we need to transmit a float
  radio.setPayloadSize(sizeof(payload));  // float datatype occupies 4 bytes

  // set the TX address of the RX node into the TX pipe
  radio.openWritingPipe(address[radioNumber]);  // always uses pipe 0

  // set the RX address of the TX node into a RX pipe
  radio.openReadingPipe(1, address[!radioNumber]);  // using pipe 1

  // additional setup specific to the node's role
  radio.startListening();  // put radio in RX mode */

	
  // For debugging info
  // printf_begin();             // needed only once for printing details
  // radio.printDetails();       // (smaller) function that prints raw register values
  // radio.printPrettyDetails(); // (larger) function that prints human readable data

}  // setup

void loop() {

	// This device is a RX node
	uint8_t pipe;
	// is there a payload? get the pipe number that recieved it
	if (radio.available(&pipe)) { 
		uint8_t bytes = radio.getPayloadSize();  // get the size of the payload
		radio.read(&payload, bytes);             // fetch payload from FIFO
#ifdef DEBUG
		Serial.print(F("Received "));
		Serial.print(bytes);  // print the size of the payload
		Serial.print(F(" bytes on pipe "));
		Serial.print(pipe);  // print the pipe number
		Serial.print(F(": "));
#endif
		Serial.println(payload);  // print the payload's value
	}

}  // loop

