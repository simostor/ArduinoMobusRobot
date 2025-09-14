#pragma once
#include <Arduino.h>
// Functions
int add(int a, int b);

void RestrictServo(uint16_t inputVal, uint16_t lowerLimit, uint16_t upperLimit);


// Enumerators
enum ControlMode
{
    LocalControl,
    RemoteControl,
    LocalEmergencyStop,
    RemoteEmergencyStop
};

// Structs



// Classes