# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'distancesensorultrasoniclcd.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_distanceSensorUltrasonicLCD(object):
    def setupUi(self, distanceSensorUltrasonicLCD):
        distanceSensorUltrasonicLCD.setObjectName("distanceSensorUltrasonicLCD")
        distanceSensorUltrasonicLCD.resize(1438, 978)
        self.centralWidget = QtWidgets.QWidget(distanceSensorUltrasonicLCD)
        self.centralWidget.setObjectName("centralWidget")
        self.horizontalLayoutWidget = QtWidgets.QWidget(self.centralWidget)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(20, 170, 121, 591))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setContentsMargins(11, 11, 11, 11)
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.QwtSliderDistance = QwtSlider(self.horizontalLayoutWidget)
        self.QwtSliderDistance.setUpperBound(400.0)
        self.QwtSliderDistance.setProperty("value", 10.0)
        self.QwtSliderDistance.setObjectName("QwtSliderDistance")
        self.horizontalLayout.addWidget(self.QwtSliderDistance)
        self.QwtPlotDistance = QwtPlot(self.centralWidget)
        self.QwtPlotDistance.setGeometry(QtCore.QRect(327, 164, 961, 631))
        self.QwtPlotDistance.setMaximumSize(QtCore.QSize(961, 631))
        self.QwtPlotDistance.setAutoReplot(False)
        self.QwtPlotDistance.setObjectName("QwtPlotDistance")
        self.QwtTextLabelDistance = QwtTextLabel(self.centralWidget)
        self.QwtTextLabelDistance.setGeometry(QtCore.QRect(160, 440, 147, 77))
        self.QwtTextLabelDistance.setObjectName("QwtTextLabelDistance")
        self.verticalLayoutWidget = QtWidgets.QWidget(self.centralWidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(170, 460, 149, 79))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout.setSpacing(6)
        self.verticalLayout.setObjectName("verticalLayout")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setSpacing(6)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.verticalLayout.addLayout(self.verticalLayout_3)
        distanceSensorUltrasonicLCD.setCentralWidget(self.centralWidget)
        self.menuBar = QtWidgets.QMenuBar(distanceSensorUltrasonicLCD)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 1438, 39))
        self.menuBar.setObjectName("menuBar")
        self.menudistanceSensorUltrasonicLCD = QtWidgets.QMenu(self.menuBar)
        self.menudistanceSensorUltrasonicLCD.setObjectName("menudistanceSensorUltrasonicLCD")
        distanceSensorUltrasonicLCD.setMenuBar(self.menuBar)
        self.mainToolBar = QtWidgets.QToolBar(distanceSensorUltrasonicLCD)
        self.mainToolBar.setObjectName("mainToolBar")
        distanceSensorUltrasonicLCD.addToolBar(QtCore.Qt.TopToolBarArea, self.mainToolBar)
        self.statusBar = QtWidgets.QStatusBar(distanceSensorUltrasonicLCD)
        self.statusBar.setObjectName("statusBar")
        distanceSensorUltrasonicLCD.setStatusBar(self.statusBar)
        self.menuBar.addAction(self.menudistanceSensorUltrasonicLCD.menuAction())

        self.retranslateUi(distanceSensorUltrasonicLCD)
        QtCore.QMetaObject.connectSlotsByName(distanceSensorUltrasonicLCD)

    def retranslateUi(self, distanceSensorUltrasonicLCD):
        _translate = QtCore.QCoreApplication.translate
        distanceSensorUltrasonicLCD.setWindowTitle(_translate("distanceSensorUltrasonicLCD", "distanceSensorUltrasonicLCD"))
        self.QwtTextLabelDistance.setPlainText(_translate("distanceSensorUltrasonicLCD", "Value"))
        self.menudistanceSensorUltrasonicLCD.setTitle(_translate("distanceSensorUltrasonicLCD", "dista&nceSensorUltrasonicLCD"))

from qwt_plot import QwtPlot
from qwt_slider import QwtSlider
from qwt_text_label import QwtTextLabel
