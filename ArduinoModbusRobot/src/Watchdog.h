#pragma once
#include <Arduino.h>

class Watchdog {
public:
    void setTimeout(uint16_t ms);
    void tick(uint16_t plcHeartbeat, uint32_t nowMs);
    bool isOk() const;
    void reset();
private:
    uint16_t lastHb = 0;
    uint32_t lastChange = 0;
    uint16_t timeoutMs = 150;
    bool ok = false;
};
