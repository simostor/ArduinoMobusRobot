#include <Arduino.h>
#include <ModbusRtu.h>
#include <Servo.h>
#include <CustomLibrary.h>
#include <Config.h>
#include <Safety.h>
#include <Watchdog.h>
#include <Types.h>


Modbus slave(MB_ID, 0, 0);  // this is slave @1 and RS-232 or USB-FTDI
Servo BaseServo;
Servo ShoulderServoA;
Servo ShoulderServoB;
Servo ElbowServo;
uint16_t au16data[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t SizeOfMBArray = 0;

// Analog inputs
uint16_t potVal1 = 0;
uint16_t potVal2 = 0;
uint16_t potVal3 = 0;
uint16_t potVal4 = 0;


// Control with potentiomenters (local control) or from PLC over modbus rtu (remote control)
ControlMode controlMode = LocalControl; // Initially in local control

Watchdog MB_Watchdog;


void setup() {
  slave.begin(Modbus_BaudRate);  // baud-rate
  BaseServo.attach(baseServoPin);
  ShoulderServoA.attach(shoulderServoAPin);
  ShoulderServoB.attach(shoulderServoBPin);
  ElbowServo.attach(elbowServoPin);

  // Defining functionality of pins:
  pinMode(DI_LocalModeSwitch, INPUT_PULLUP);


  MB_Watchdog.setTimeout(watchdogTimeoutMax_ms);
  SizeOfMBArray = sizeof(au16data)/sizeof(au16data[0]);
}

void loop() {
slave.poll(au16data, SizeOfMBArray);
au16data[6] = au16data[15]; // Updating watchdog
BaseServo.write(au16data[10]);
ShoulderServoA.write(au16data[11]);
ShoulderServoB.write(au16data[12]);
ElbowServo.write(au16data[13]);
}