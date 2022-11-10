#ifndef DISTANCESENSORULTRASONICLCD_H
#define DISTANCESENSORULTRASONICLCD_H

#include <QMainWindow>

namespace Ui {
  class distanceSensorUltrasonicLCD;
}

class distanceSensorUltrasonicLCD : public QMainWindow
{
  Q_OBJECT

public:
  explicit distanceSensorUltrasonicLCD(QWidget *parent = 0);
  ~distanceSensorUltrasonicLCD();

private:
  Ui::distanceSensorUltrasonicLCD *ui;
};

#endif // DISTANCESENSORULTRASONICLCD_H
