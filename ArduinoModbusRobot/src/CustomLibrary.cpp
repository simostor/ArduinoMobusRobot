#include "CustomLibrary.h"

int add(int a, int b){
    return a + b;
}

// Restricting value based on lower and upper limits defined
void RestrictServo(uint16_t inputVal, uint16_t lowerLimit, uint16_t upperLimit)
{
  if (inputVal > upperLimit) {
    inputVal = 180;
  } else if (inputVal <= lowerLimit) {
    inputVal = 0;
  }
};