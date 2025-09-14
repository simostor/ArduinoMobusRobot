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

// Control with potentiomenters (local control) or from PLC over modbus rtu (remote control)
ControlMode controlMode = LocalControl; // Initially in local control

Watchdog MB_Watchdog;


void setup() {
  slave.begin(Modbus_BaudRate);  // baud-rate
  BaseServo.attach(baseServoPin);
  ShoulderServoA.attach(shoulderServoAPin);
  ShoulderServoB.attach(shoulderServoBPin);
  ElbowServo.attach(elbowServoPin);
  MB_Watchdog.setTimeout(watchdogTimeoutMax_ms);
}

void loop() {
  slave.poll(au16data, sizeof(au16data)/sizeof(au16data[0]));

  MB_Watchdog.tick(au16data[8], millis());

  // Reading inputs
  potVal1 = analogRead(A0);
  potVal2 = analogRead(A1);
  potVal3 = analogRead(A2);
  potVal4 = analogRead(A3);

  au16data[0] = map(potVal1, 0, 1023, 0, 180);
  au16data[1] = map(potVal2, 0, 1023, 0, 180); 
  au16data[2] = map(potVal3, 0, 1023, 0, 180);
  au16data[3] = map(potVal4, 0, 1023, 0, 180);
  au16data[10] = map(au16data[10], 0, 1023, 0, 180);
  au16data[11] = map(au16data[11], 0, 1023, 0, 180); 
  au16data[12] = map(au16data[12], 0, 1023, 0, 180);
  au16data[13] = map(au16data[13], 0, 1023, 0, 180);

  if (controlMode == LocalControl){
       BaseServo.write(au16data[0]);
       ShoulderServoA.write(au16data[1]);
       ShoulderServoB.write(au16data[2]);
       ElbowServo.write(au16data[3]);
     }
  if (controlMode == RemoteControl)
  {
    if (MB_Watchdog.isOk())
    {
      BaseServo.write(au16data[10]);
      ShoulderServoA.write(au16data[11]);
      ShoulderServoB.write(au16data[12]);
      ElbowServo.write(au16data[13]);
    }
    else
    {
      BaseServo.write(90);
      ShoulderServoA.write(90);
      ShoulderServoB.write(90);
      ElbowServo.write(90);
    }
  }
}