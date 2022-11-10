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
#include <NewPing.h>
#include "LowPower.h"
#include <avr/sleep.h>

// Enable debug mode.  Normally it is off in operation as we want the
// arduino to use as little power as possible.  The TX/RX leds will
// pull about 20ma when they are operational.
#define DEBUG 

#define TRIGGER_PIN  3
#define ECHO_PIN     4
#define MAX_DISTANCE 500

unsigned long duration;

// instantiate ultrasonic sensor and servo objects
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// instantiate an object for the nRF24L01 transceiver
RF24 radio(7, 8);  // using pin 7 for the CE pin, and pin 8 for the CSN pin

// Let these addresses be used for the pair
uint8_t address[][6] = { "1Node", "2Node" };
// It is very helpful to think of an address as a path instead of as
// an identifying device destination

// to use different addresses on a pair of radios, we need a variable to
// uniquely identify which address this radio will use to transmit
bool radioNumber = 1;  // 0 uses address[0] to transmit, 1 uses address[1] to transmit
// RX expects radionumber 0 for RX in tank_level sms code

// Used to control whether this node is sending or receiving
bool role = true;  // true = TX role, false = RX role

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

	// You need to turn off the power always on LED to save about 20ma,
	// only way to do this is to solder it off the board.
//	pinMode(LED_BUILTIN,OUTPUT);
//  digitalWrite(LED_BUILTIN,LOW);
	
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
	radio.stopListening();  // put radio in TX mode


  // For debugging info
  // printf_begin();             // needed only once for printing details
  // radio.printDetails();       // (smaller) function that prints raw register values
  // radio.printPrettyDetails(); // (larger) function that prints human readable data

	
}  // setup

void loop() {


	// Put arduino to low power use mode for about 1 day
	for (unsigned int j=0; j<24; j++){
		for (unsigned int i = 0; i<360; i++){ 
			// ADC, timers, SPI, USART, and the 2-wire interface TWI. 
			//LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,SPI_OFF,
			//							USART0_OFF, TWI_OFF);

			// SLEEP_FOREVER only allows internal and external interrupt to wake arduino.
			//

			// ADC and brown-out  detect BOD are disabled, this  is the lowest 
			// power  consumption mode.   Internal Timer  interrupt only  does 
			// about 8sec max anyhow so no need to complicate the code. 
			LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
		}

		//Serial.print("tmin=");
		//Serial.println(j);
		delay(2000); // to allow serial output and a bit of time to exit LowPower

	}
	
	// This device is a TX node

	unsigned long start_timer = micros();                // start the timer
	bool report = radio.write(&payload, sizeof(float));  // transmit & save the report
	//	bool report = radio.write(&payload, sizeof(String));  // transmit & save the report
	unsigned long end_timer = micros();                  // end the timer

	if (report) {
#ifdef DEBUG
		Serial.print(F("Transmission successful! "));  // payload was delivered
		Serial.print(F("Time to transmit = "));
		Serial.print(end_timer - start_timer);  // print the timer result
		Serial.print(F(" us. Sent: "));
#endif
		unsigned long distance = calculateDistance();
		payload = distance;
			
		Serial.println(payload);  // print payload sent
		//payload += 0.01;          // increment float payload
//			payload = "hello world";          // increment float payload
	} else {
#ifdef DEBUG
		Serial.println(F("Transmission failed or timed out"));  // payload was not delivered
#endif
	}

	// to make this example readable in the serial monitor
	delay(2000);
	//delay(60000);  // slow transmissions down by 1 second

}  // loop




long calculateDistance(){

    // using ultrasonic sensor HC-SR04
    
    unsigned long duration = 0; // micro-seconds for ECHO to return
    int tries = 0;
    
    delay(50);
    //delay(30);
    //do{
    duration = sonar.ping_cm();
    //if (duration == 0 && digitalRead(ECHO_PIN) == HIGH) {
    //if (duration == 0){
      pinMode(ECHO_PIN, OUTPUT);
      digitalWrite(ECHO_PIN, LOW);
      //delay(100);
      pinMode(ECHO_PIN, INPUT);    
    //}
    //} while (duration == 0 && ++tries < 3);
    //duration = sonar.ping_cm() * 29.1 * 2;


    // dataSheet:
    // range(metres) = (duration/2/100000)s * 340m/s(speed of sound)
		// OR
		// range(metres)= duration/58
    //
    // the computer can convert to proper numbers.
    // by duration/29.1 seconds
    return duration;
}
