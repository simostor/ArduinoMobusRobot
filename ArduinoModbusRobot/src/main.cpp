#include <Arduino.h>
#include <ModbusRtu.h>
#include <Servo.h>

const int ledPin = 3;  // LED connected to digital pin 3 (PWM pin)

uint16_t analogReceive1 = 0;
uint16_t analogReceive2 = 0;
uint16_t analogReceive3 = 0;
uint16_t analogReceive4 = 0;
uint16_t potVal1 = 0;
uint16_t potVal2 = 0;
uint16_t potVal3 = 0;
uint16_t potVal4 = 0;


// registers in the slave
uint16_t au16data[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int counter = 0;

Modbus slave(1, 0, 0);  // this is slave @1 and RS-232 or USB-FTDI
Servo BaseServo;
Servo ShoulderServoA;
Servo ShoulderServoB;
Servo ElbowServo;

void setup() {
  slave.begin(38400);  // baud-rate
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  BaseServo.attach(9);
  ShoulderServoA.attach(10);
  ShoulderServoB.attach(11);
  ElbowServo.attach(6);
}

void loop() {
  // Reading inputs
  potVal1 = analogRead(A0);
  potVal2 = analogRead(A1);
  potVal3 = analogRead(A2);
  potVal4 = analogRead(A3);

  // Updating modbus registers to be read
  au16data[4] = map(potVal1, 0, 1023, 0, 180);
  au16data[5] = map(potVal2, 0, 1023, 0, 180); 
  au16data[6] = map(potVal3, 0, 1023, 0, 180);
  au16data[7] = map(potVal4, 0, 1023, 0, 180); 
  
  slave.poll(au16data, 20);



  BaseServo.write(au16data[4]);
  ShoulderServoA.write(au16data[5]);
  ShoulderServoB.write(au16data[6]);
  ElbowServo.write(au16data[7]);


}



// Functions
void restrictServo(uint16_t servoValue)
{
  if (servoValue > 180) {
    servoValue = 180;
  } else if (servoValue <= 0) {
    servoValue = 0;
  }
};