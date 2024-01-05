#pragma once

#include "diode.h"


enum DiodeType {
    D_DIODE,
    D_ZENER,
    D_LED
};

class DiodeFactory {
public:
    static diode* createDiode(DiodeType diodeType, const std::string& smdSize, double bwVoltage = 0.0, double bwAmperage = 0.0);
};

