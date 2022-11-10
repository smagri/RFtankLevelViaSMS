from PyQt5.QtWidgets import QApplication, QLabel, QVBoxLayout


app = QApplication([])

label = QLabel('Hello World!')

label.show()

# start event loop. note: exec is a python keyword so exec_ is required
app.exec_()
