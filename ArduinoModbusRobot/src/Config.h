#pragma once
#include <Arduino.h>



constexpr uint8_t DI_LocalModeSwitch = 8; // 0 - remote, 1, local
constexpr uint8_t switch2 = 6;
constexpr uint8_t switch3 = 7;
constexpr uint8_t switch4 = 8;

// Outputs
constexpr int baseServoPin = 4;
constexpr int shoulderServoAPin = 5;
constexpr int shoulderServoBPin = 9;
constexpr int elbowServoPin = 10;

// Modbus
constexpr uint8_t MB_ID = 1;
constexpr long int Modbus_BaudRate = 38400;

// Joint limits
constexpr uint16_t baseAngleMin = 0;
constexpr uint16_t baseAngleMax = 180;
constexpr uint16_t shoulderAngleMin = 0;
constexpr uint16_t shoulderAngleMax = 180;
constexpr uint16_t elbowAngleMin = 0;
constexpr uint16_t elbowAngleMax = 180;

constexpr float slowSpeed = 5.0f; // [deg/s]
constexpr float fastSpeed = 10.0f; // [deg/s]

constexpr uint8_t SafePos[4] = {90, 90, 90, 90};

constexpr int watchdogTimeoutMax_ms = 150;