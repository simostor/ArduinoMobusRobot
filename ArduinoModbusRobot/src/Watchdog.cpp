#include "Watchdog.h"

void Watchdog::setTimeout(uint16_t ms) { timeoutMs = ms; }

void Watchdog::tick(uint16_t plcHeartbeat, uint32_t nowMs) {
    if (plcHeartbeat != lastHb) {
        lastHb = plcHeartbeat;
        lastChange = nowMs;
        ok = true;
    } else if (nowMs - lastChange > timeoutMs) {
        ok = false;
    }
}

bool Watchdog::isOk() const { return ok; }

void Watchdog::reset() {
    lastHb = 0;
    lastChange = 0;
    ok = false;
}
