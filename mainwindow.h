#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionEvent>
#include "modbusclient.h"
#include "modbusserver.h"
#include "settingswindow.h"
#include "qjoystick.h"
#include "rover.h"
#include "manipulator.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void createManipulatorJoystick(int id);
  void createRoverJoystick(int id);
private slots:
  void showSettingsWindow();
  void connectToHostManipulator(QString ip,int port );
  void connectToHostRover(QString ip,int port);
  void disconnectFromHostManipulator();
  void disconnectFromHostRover();
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;

  ModbusServer *myModbusServer;
  Rover *myRover;
  //ModbusClient *myModbusClient;

  Manipulator *myManipulator;
  //Windows
  SettingsWindow *mySettingsWindow;

  QJoystick *myJoystickRover;
  QJoystick *myJoystickManipulator;

  QTimer *joypadRoverRefresh;
  QTimer *joypadManipulatorRefresh;

  QTimer *roverRefresh;
  QTimer *manipulatorRefresh;
};

#endif // MAINWINDOW_H
