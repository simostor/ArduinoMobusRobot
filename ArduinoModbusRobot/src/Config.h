#pragma once
#include <Arduino.h>

// Inputs
const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;
const int switch1 = 8;
const int switch2 = 9;
const int switch3 = 10;
const int switch4 = 11;

// Outputs
const int baseServoPin = 4;
const int shoulderServo1Pin = 5;
const int shoulderServo2Pin = 6;
const int elbowServoPin = 7;

// registers in the slave
uint16_t modbusRegs[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // 0 - 9: Readable by 

// Joint limits
uint16_t baseAngleMin = 0;
uint16_t baseAngleMax = 180;
uint16_t shoulderAngleMin = 0;
uint16_t shoulderAngleMax = 180;
uint16_t elbowAngleMin = 0;
uint16_t elbowAngleMax = 180;

const float slowSpeed = 5.0; // [deg/s]
const float fastSpeed = 10.0; // [deg/s]

const int watchdogTimeoutMax_ms = 150;

