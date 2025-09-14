#pragma once
#include <Arduino.h>

// Inputs
uint16_t potVal1 = 0;
uint16_t potVal2 = 0;
uint16_t potVal3 = 0;
uint16_t potVal4 = 0;
uint16_t analogReceive1 = 0;
uint16_t analogReceive2 = 0;
uint16_t analogReceive3 = 0;
uint16_t analogReceive4 = 0;

const int switch1 = 8;
const int switch2 = 9;
const int switch3 = 10;
const int switch4 = 11;

// Outputs
const int baseServoPin = 4;
const int shoulderServoAPin = 5;
const int shoulderServoBPin = 6;
const int elbowServoPin = 7;

// Modbus
const byte MB_ID = 1;
uint16_t au16data[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
long int Modbus_BaudRate = 38400;

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

