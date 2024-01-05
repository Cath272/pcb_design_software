//
// Created by Beaver on 04/01/2024.
//

#include "../headers/diodeFactory.h"

#include "../headers/diodeFactory.h"

diode* DiodeFactory::createDiode(DiodeType diodeType, const std::string& smdSize, double bwVoltage, double bwAmperage) {
    switch (diodeType) {
        case D_DIODE:
            return new diode(smdSize);
        case D_ZENER:
            return new zener_diode(smdSize, bwVoltage, bwAmperage);
        case D_LED:
        {
            LED* led = new LED(smdSize);
            led->set_led();  // Set LED properties like color and voltage
            return led;
        }
        default:
            throw std::logic_error("Invalid Diode Type");
    }
}
