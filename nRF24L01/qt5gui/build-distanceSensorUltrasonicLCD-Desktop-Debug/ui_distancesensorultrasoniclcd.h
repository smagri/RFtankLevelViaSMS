/********************************************************************************
** Form generated from reading UI file 'distancesensorultrasoniclcd.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTANCESENSORULTRASONICLCD_H
#define UI_DISTANCESENSORULTRASONICLCD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"
#include "qwt_slider.h"
#include "qwt_text_label.h"

QT_BEGIN_NAMESPACE

class Ui_distanceSensorUltrasonicLCD
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QwtSlider *QwtSliderDistance;
    QwtPlot *QwtPlotDistance;
    QwtTextLabel *QwtTextLabelDistance;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QMenu *menudistanceSensorUltrasonicLCD;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *distanceSensorUltrasonicLCD)
    {
        if (distanceSensorUltrasonicLCD->objectName().isEmpty())
            distanceSensorUltrasonicLCD->setObjectName(QString::fromUtf8("distanceSensorUltrasonicLCD"));
        distanceSensorUltrasonicLCD->resize(1438, 978);
        centralWidget = new QWidget(distanceSensorUltrasonicLCD);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 170, 121, 591));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        QwtSliderDistance = new QwtSlider(horizontalLayoutWidget);
        QwtSliderDistance->setObjectName(QString::fromUtf8("QwtSliderDistance"));
        QwtSliderDistance->setUpperBound(400);
        QwtSliderDistance->setValue(10);

        horizontalLayout->addWidget(QwtSliderDistance);

        QwtPlotDistance = new QwtPlot(centralWidget);
        QwtPlotDistance->setObjectName(QString::fromUtf8("QwtPlotDistance"));
        QwtPlotDistance->setGeometry(QRect(327, 164, 961, 631));
        QwtPlotDistance->setMaximumSize(QSize(961, 631));
        QwtPlotDistance->setAutoReplot(false);
        QwtTextLabelDistance = new QwtTextLabel(centralWidget);
        QwtTextLabelDistance->setObjectName(QString::fromUtf8("QwtTextLabelDistance"));
        QwtTextLabelDistance->setGeometry(QRect(160, 440, 147, 77));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(170, 460, 149, 79));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        verticalLayout->addLayout(verticalLayout_3);

        distanceSensorUltrasonicLCD->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(distanceSensorUltrasonicLCD);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1438, 39));
        menudistanceSensorUltrasonicLCD = new QMenu(menuBar);
        menudistanceSensorUltrasonicLCD->setObjectName(QString::fromUtf8("menudistanceSensorUltrasonicLCD"));
        distanceSensorUltrasonicLCD->setMenuBar(menuBar);
        mainToolBar = new QToolBar(distanceSensorUltrasonicLCD);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        distanceSensorUltrasonicLCD->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(distanceSensorUltrasonicLCD);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        distanceSensorUltrasonicLCD->setStatusBar(statusBar);

        menuBar->addAction(menudistanceSensorUltrasonicLCD->menuAction());

        retranslateUi(distanceSensorUltrasonicLCD);

        QMetaObject::connectSlotsByName(distanceSensorUltrasonicLCD);
    } // setupUi

    void retranslateUi(QMainWindow *distanceSensorUltrasonicLCD)
    {
        distanceSensorUltrasonicLCD->setWindowTitle(QApplication::translate("distanceSensorUltrasonicLCD", "distanceSensorUltrasonicLCD", 0, QApplication::UnicodeUTF8));
        QwtTextLabelDistance->setPlainText(QApplication::translate("distanceSensorUltrasonicLCD", "Value", 0, QApplication::UnicodeUTF8));
        menudistanceSensorUltrasonicLCD->setTitle(QApplication::translate("distanceSensorUltrasonicLCD", "dista&nceSensorUltrasonicLCD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class distanceSensorUltrasonicLCD: public Ui_distanceSensorUltrasonicLCD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTANCESENSORULTRASONICLCD_H
