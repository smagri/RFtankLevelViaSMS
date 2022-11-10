#include "distancesensorultrasoniclcd.h"
#include "ui_distancesensorultrasoniclcd.h"

distanceSensorUltrasonicLCD::distanceSensorUltrasonicLCD(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::distanceSensorUltrasonicLCD)
{
  ui->setupUi(this);

  //ui->sliderDistance->setRange(0, 100, 1, 1); // min,max,step,page
  //ui->sliderDistance->setScale(1, 100, 5); // min,max,step
  //ui->sliderDistance->setScaleMaxMinor(5); // max num of minor ticks
  //ui->sliderDistance->setValue(readInt);
  ui->TextLabelDistanceValue->setText("300");


}

distanceSensorUltrasonicLCD::~distanceSensorUltrasonicLCD()
{

  // delete all heap stuff, ie a 'new' allocated space stuff
  delete ui;
}
