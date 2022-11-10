#!/usr/bin/env python3.6

# TO RUN:  enter the  serial port  you are using  on the  command line,
# argv[1], eg "/dev/ttyUSB".  argv[0] is the program name.


import sys
import serial
import io
import time
#import dsuLCDpyqt5
#from dsuLCDpyqt5 import dsuLCDpyqt5

#imports all the modules you need to create a GUI into the current namespace
#from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget
#from PyQt5.QtGui import QPalette

def main():
    # Creating an object of the  QApplication class. Every UI app must
    # create an  instance of  QApplication, as a  sort of  entry point
    # into the app. If you do not create it, errors will be shown.

    # sys.argv is  the list  of command-line  parameters that  you can
    # pass to the  application when launching it through  the shell or
    # while automating  the interface.  Use app  = QApplication([]) if
    # no arguments will be passed.
    app = QApplication(sys.argv)
    #  set a syle, can be fusion, windows, mac..app.setStyle("Fusion")

    # Start the Qt/C++ event loop.
    ex = dsuLCDpyqt5()
    # note: exec_ is used in instead of exec as this is a python keywoard
    sys.exit(app.exec_())

    # return from Qt event loop as program dialog/main widget window killed
    serialPort.close()    


if __name__ == "__main__":
    main()
    

