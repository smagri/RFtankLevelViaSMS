#!/usr/bin/python3

###############################################################################
# MUST SET for this to work under wayland, see README:
#  setenv XDG_SESSION_TYPE xcb
###############################################################################

# see for this example code:
# https://zetcode.com/gui/pyqt5/firstprograms/

# """
# ZetCode PyQt5 tutorial

# This example shows an icon
# in the titlebar of the window.

# Author: Jan Bodnar
# Website: zetcode.com
# """

import sys
import serial
import io
import time

from PyQt5.QtGui import QIcon
#imports all the modules you need to create a GUI into the current namespace
#from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget, QTextEdit, QLineEdit
#from PyQt5.QtGui import QPalette


from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPalette



class dsuLCDpyqt5(QWidget):

    ############################################################################
    # REMEMBER self refers to the QWidget, not other nested widgets in the UI. #
    ############################################################################
    
    def __init__(self):
        super().__init__()

        # main window title
        self.title = "Ultrasonic Distance Sensor with LCD display"

        # where to position the window in your screen
        self.left = 10
        self.top = 10

        # for window geometry
        self.width = 700
        self.height = 480
        
        self.initUI()


    def initUI(self):

        # set parent widget, => self. title and geometry
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)


        #
        # all the QtWidgets inherit from the QtWidget class as class
        # definition indicates and this is denoted by self
        #
        labelPCBdetails = QLabel("(using HCSR04 with 1602LCD)", self)
        labelPCBdetails.move(125,10) #(from_left, from_top)
        labelGap = QLabel(self)
        labelGap.move(125,40) #(from_left, from_top)
        labelGap1 = QLabel(self)
        labelGap1.move(125,80) #(from_left, from_top)
        labelGap2 = QLabel(self)
        labelGap2.move(125,120)#(from_left, from_top)


        labelRun = QLabel("TO RUN:  \n"
                          "argv[0] \"serial port name\", don't forget to quote it.", self)
        print("TO RUN:  argv[0] \"serial port name, dont forget to quote it\n")
        labelRun.move(10,160)#(from_left, from_top)
        # argv[1], eg "/dev/ttyUSB0".  argv[0] is the program name.
        
        labelGap3 = QLabel(self)
        labelGap3.move(125,200)
        labelDistance = QLabel("Distance (cm)", self)
        labelDistance.move(10,258)
        
        #vbox = QVBoxLayout(self)
        #vbox.addWidget(self, labelPCBdetails)
        # vbox.addWidget(self, labelGap)
        # vbox.addWidget(self, labelGap1)
        # vbox.addWidget(self, labelGap2)
        # vbox.addWidget(self, labelGap3)
        # vbox.addWidget(self, labelDistance)


        
        #labelGap = QLabel("1", self)
        # labelGap.move(125,40) #(from_left, from_top)
        # labelGap1 = QLabel("2", self)
        # labelGap1.move(125,80) #(from_left, from_top)
        # labelGap2 = QLabel("3", self)
        # labelGap2.move(125,120)#(from_left, from_top)

        #vbox = QVBoxLayout(self)
#        vbox.addWidget(labelTitle)
        #vbox.addWidget(labelPCBdetails)
        #vbox.addWidget(labelGap)
        #vbox.addWidget(labelGap1)

                        



        
        self.show()


def main():

    app = QApplication(sys.argv)
    ex = dsuLCDpyqt5()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

