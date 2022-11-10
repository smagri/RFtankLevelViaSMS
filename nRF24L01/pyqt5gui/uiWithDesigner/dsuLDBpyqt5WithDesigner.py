#!/usr/bin/env python3

# Import sys module
import sys

# Import QtWidgets and uic modules
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.uic import loadUi


if __name__ == "__main__":

    # Create app object
    app = QApplication(sys.argv)

    # Load GUI form and display
    window = uic.loadUi("distanceSensorUltrasonicLCD.PyQt5.ui")
    window.show()

    # Start the event loop of the app or dialog box
    sys.exit(app.exec_())
