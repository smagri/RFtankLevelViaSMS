#!/usr/bin/env python3

import sys
import serial
import io
import time

portNameStr = "/dev/ttyACM2"
print("opening serial port")
serialPort = serial.Serial(portNameStr, 9600, timeout=1)
#line = serialPort.read(100)
line = serialPort.readline()
print("line is=", line)
#serialPort.close()

# while True:
#     serialPort = serial.Serial(portNameStr, 9600, timeout=2)
#     #line = serialPort.read(100)
#     line = str(serialPort.readline())
#     print("line is=", line)
#     serialPort.close()

while True:
     line = str(serialPort.readline())
     print("line is=", line)


serialPort.close()


