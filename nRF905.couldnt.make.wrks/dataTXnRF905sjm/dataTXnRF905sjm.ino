// References:
//
//
// https://github.com/zkemble/nRF905-arduino/blob/master/examples/lowpwr_node_sensor/lowpwr_node_sensor.ino
//
/*
 * Project: nRF905 Radio Library for Arduino (Low power sensor node example)
 * Author: Zak Kemble, contact@zakkemble.net
 * Copyright: (C) 2020 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: https://blog.zakkemble.net/nrf905-avrarduino-librarydriver/
 */
//
// This examples requires the low power library from
// https://github.com/rocketscream/Low-Power
//
// This examples configures the nRF905 library to only use 5 connections:
// MOSI
// MISO
// SCK
// SS -> 6
// PWR -> 8

// The following pins on the nRF905 must be connected to VCC (3.3V) or GND:
// CE (TRX_EN) -> VCC
// TXE (TX_EN) -> VCC Thus, is the transmitter TX.


#include <nRF905.h>
#include <SPI.h>
/* TODO:  */
//#include <LowPower.h>
#include <NewPing.h>
#include <Servo.h>


// nRF905 RF transceiver
#define BASE_STATION_ADDR	0xE7E7E7E7
#define NODE_ID	78
#define LED	A5
#define PAYLOAD_SIZE_DISTANCE_SENSOR 10

// Ultrasonic sensor
#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define MAX_DISTANCE 500
#define SERVO A1


// Instantiate objects
nRF905 transceiver = nRF905();
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


// NOTE: In polling mode this does not need to be volatile, default
// mode used here uses interrupts so it needs to be volatile I think.
//static bool txDone;
/* TODO:  */
static volatile bool txDone;


//
// NOTE: EVENTS ARE DIFFERENT TO INTERRUPTS.  Interrupts have ISR's as
// callback_interrup_dr  and  callback_interrup_am  are,  see  doxygen
// documentation.
//

// Event function for TX completion
//
// (Only works when calling TX() with NRF905_NEXTMODE_TX or
// NRF905_NEXTMODE_STANDBY)
void nRF905_onTxComplete(nRF905* device)
{
	txDone = true;
}



void setup()
	
{
	Serial.begin(115200);
	Serial.println(F("Sensor node(Transmitter) starting..."));
	
	pinMode(LED, OUTPUT);


	// standby off TODO
	//pinMode(7, OUTPUT);
	//digitalWrite(7, HIGH);
	// pwr
	//pinMode(8, OUTPUT);
	//digitalWrite(8, HIGH);
	// trx
	//pinMode(9, OUTPUT);
	//digitalWrite(9, HIGH);
	
	
	// This must be called first
	SPI.begin();

	/***************************************************************************/
/*                      Minimal wires, polling modedate                     */
/*****************************************************************************/
	/* Minimal wires (polling  mode) Up to 5 wires  can be disconnected, */
	/* however this will  reduce functionalliy and will  put the library */
	/* into polling mode instead of interrupt mode.  In polling mode the */
	/* .poll() method must be called as often as possible. If .poll() is */
	/* not called often enough then events may be missed. */
	transceiver.begin(
		SPI,
		10000000,
		6,
		NRF905_PIN_UNUSED, // CE (standby) pin must be connected to VCC (3.3V)
		NRF905_PIN_UNUSED, // TRX (RX/TX mode) pin must be connected to
											 // VCC (3.3V) (force TX mode)
		8, // PWR
		NRF905_PIN_UNUSED, // Without the CD pin collision avoidance will be disabled
		NRF905_PIN_UNUSED, // Without the DR pin the library will run in
											 // polling mode and poll the status register
											 // over SPI. This also means the nRF905 can not
											 // wake the MCU up from sleep mode
		NRF905_PIN_UNUSED, // Without the AM pin the library must poll the
											 // status register over SPI.
		NULL, // Running in polling mode so no interrupt function
		NULL // Running in polling mode so no interrupt function
	);

 
	// If TX is not used and conneted to VCC(TX mode) then either TRX(ie
	// CE)  or PWR  must  be used  otherwise the  radio  will always  be
	// transmitting either  an empty carrier wave  or if auto-retransmit
	// is enabled then the payload is retransmitted over and over again.
	//
	// Default mode is interrupt mode.
	/* transceiver.begin( */
	/* 	SPI, */
	/* 	10000000, // SPI clock rate, max 10MHz(10000000Hz) */

	/* 	10, // CSN SPI Slave select pin, SPI SS. */

	/* 	// CE/TRX_EN, Chip  Enable pin, HIGH =>  TX or RX ENabled,  LOW => */
	/* 	// Standby mode. */
	/* 	// */
	/* 	// OPTIONAL, must be connected to VCC (3.3V) if not used. */
	/* 	7, */

	/* 	// TXEN(TX/RX HIGH/LOW mode ENable) pin, TX=>HIGH, ie +3.3V. */
	/* 	// */
	/* 	// OPTIONAL, must be connected to VCC(TX) or GND(RX) if not used */
	/* 	// depending on what the radio should do. */
	/* 	9, */

	/* 	/\* TODO:  *\/ */
	/* 	// PWR, power-down control, HIGH=>power on, LOW=>power off. */
	/* 	// */
	/* 	// OPTIONAL, must be connected to VCC if not used. */
	/* 	8, */

	/* 	// CD(Carrier  Detect)   pin,  high   when  signal   is  detected. */
	/* 	// Collision   avoidance    will   be   disabled    without   this */
	/* 	// pin. (OPTIONAL) */
	/* 	4, */

	/* 	// High when  finished transmitting(onTxComplete  event)/High when */
	/* 	// new data  recived(onRxComplete event), optional since  state is */
	/* 	// stored in  register, if interrupts are  used(default) then this */
	/* 	// pin must  be connected.  (OPTIONAL) */
	/* 	// */
	/* 	// Without the DR(Data Ready) pin  the library will run in polling */
	/* 	// mode and poll the status register over SPI. This also means the */
	/* 	// nRF905 can not wake the MCU up from sleep mode. */
	/* 	// */
	/* 	// Default mode is interrupt mode. (OPTIONAL) */
	/* 	3, */

	/* 	// High when receiving  a packet that has the same  address as the */
	/* 	// one  set  for this  device,  OPTIONAL  as  state is  stored  in */
	/* 	// register,  if interrupts  are  used(default) this  pin must  be */
	/* 	// connected. */
	/* 	// */
	/* 	// Without the AM pin the library must poll the status register */
	/* 	// over SPI.  AM(Address Match) pin. (OPTIONAL) */
	/* 	// */
	/* 	2, */

	/* 	// DR Data Ready interrupt service routine(ISR) */
	/* 	// */
	/* 	// If DR pin is not used or callabck_interrupt_dr is NULL then the */
	/* 	// library will run in polling mode.  See poll(). */
	/* 	//void callback_interrupt_dr(), */
	/* 	NULL, */
		
	/* 	// AM AddrMatch interrupt event (OPTIONAL) */
	/* 	//void callback_interrupt_am() */
	/* 	NULL */
	/* ); */


	// Register event(ie interrupts) functions
	transceiver.events(
		NULL,
		NULL,
		nRF905_onTxComplete,
		NULL
	);

	/* TODO:  */
	// Low-mid transmit level -2dBm (631uW)
	//transceiver.setTransmitPower(NRF905_PWR_n2);

	Serial.println(F("Sensor node(Transmitter) started"));
}



void loop()
{
	digitalWrite(LED, HIGH);

	// See example sketch: SPI->DigitalPotControl for testing perhaps.
  // See also: https://www.youtube.com/watch?v=ZGaCXHvgcE4

	
//	uint8_t buffer[NRF905_MAX_PAYLOAD];
	uint8_t buffer[PAYLOAD_SIZE_DISTANCE_SENSOR];

	/* unsigned long distance = calculateDistance(); */

	
	//buffer[0] = NODE_ID;
	/* buffer[0] = distance; */
	/* buffer[1] = (distance >> 8); */
	buffer[0] = 49; 
	buffer[1] = 50;
	buffer[2] = 13; // CR
	buffer[3] = 10; // LF
	/* Serial.print("Distance test data should be 12cm") */
	/* Serial.print("Distance byte 1 is: ", buffer[0]); */
	/* Serial.print("Distance byte 2 is: ", buffer[0]); */
	
	/* // debug: have i sent the right data */
	/* Serial.print(F("dbg: TX: Distance is: ")); */
	/* Serial.print(distance); */
	/* Seria.print(" cm\n"); */
	//Serial.print(F("dbg: Data to or TX client:"));
	for(uint8_t i=0;i<PAYLOAD_SIZE_DISTANCE_SENSOR;i++)
	{
//Serial.print(F(" "));
		Serial.print("Sending Payload...TX")
		Serial.print(buffer[i], DEC);
	}
	Serial.println();
		
	// Write data to radio
	transceiver.write(BASE_STATION_ADDR, buffer, sizeof(buffer));

	txDone = false;

	// This will power-up the radio and send the data
	transceiver.TX(NRF905_NEXTMODE_TX, false);

	// Transmission will take approx 6-7ms to complete (smaller paylaod
	// sizes will be faster)
	while(!txDone)
		transceiver.poll();


	// YOU CAN POWER DOWN ONCE YOU KNOW THE PACKET HAS BEEN FULLY TRANSMITTED
	//
	/* TODO:  */
	// Transmission done, power-down the radio
	//transceiver.powerDown();
	
	// NOTE: After the payload has been  sent the radio will continue to
	// transmit   an   empty   carrier  wave   until   .powerDown()   is
	// called. Since this is a sensor  node that doesn't need to receive
	// data, only transmit and go into low power mode, this example hard
	// wires the  radio into TX  mode (TXE  connected to VCC)  to reduce
	// number of connections to the  Arduino???  But in the exampele PWR
	// is used so this should not be the case???
	
	digitalWrite(LED, LOW);

	// TODO
	// Sleep for 64 seconds
	//uint8_t sleepCounter = 8;
	//while(sleepCounter--)
	// Sleep for 1 second
	//LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
}



unsigned int calculateDistance(){

	// using ultrasonic sensor HC-SR04/HC-SRF05

	// unsigned int is 16bits/2bytes in arduino
	unsigned int duration = 0; // micro-seconds for ECHO to return
	int tries = 0;
  
	delay(50);
	//delay(30);
	//do{

	// dataSheet:
	// range(metres) = (duration/2/100000)s * 340m/s(speed of sound)
	// OR
	// range(metres)= duration/58
	duration = sonar.ping_cm();
	//if (duration == 0 && digitalRead(ECHO_PIN) == HIGH) {
	//if (duration == 0){
	pinMode(ECHO_PIN, OUTPUT);
	digitalWrite(ECHO_PIN, LOW);
	//delay(100);
	pinMode(ECHO_PIN, INPUT);    
	//}
	//} while (duration == 0 && ++tries < 3);
	
	return duration;
}
