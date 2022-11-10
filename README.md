08nov2022

The aim of  this project is to  mount the TX nRF2401  interfaced to an
arduino module  under the  lid of  the water tank  and the  water tank
level, via the distance sensor HC-SR04 and the ifttt service, sends an
sms of the level once a day to my phone.

See  nRF24L01/ for  details of  arduino  code for  RF transmission  of
distance sensor values, combined with sending  an sms to me once a day
via  the ifttt  cloud service  of the  distance.  This  TX code  on an
arduino  uno,  rf.smagri.tx,  reads  the  distance  sensor  value  and
transmits the  value using  an RF  chip called  nRF2401 and  sends the
value to the  RX code on another nRF2401,  rf.smagri.rx, interfaced to
the arduino  of the Jaycar  wifi board.  The  Jaycar wifi board  has a
combined arduino and  esp8266 wifi chip on it. So  the esp8266 is used
with the  esp8266iftttJson.smagri code to  send an  sms to me  via the
ifttt service once a day. 


esp8266iftttJson.smagri/ Standalone code contains the code that sends
an sms on the jaycar esp8266 wifi board.  This was derived from
looking at internet examples and Dre's code.  It now reads a serial
string input on the serial port as is required when
GettingStarted.smagri.ino sends the rf data to it.  It uses ifttt
service with Json strings to achieve this.


esp8266ifttt/
Contains the code that sends an sms on the esp8266 01 wifi board.

All other directories are experiments or stepping stone test code.

arduinoUnoWiFi.rev2/ is testing the wifi code on the arduino wifi
where the nRF24 rf code did not work.

