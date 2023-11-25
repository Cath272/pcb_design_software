//
// Created by Beaver on 11/22/2023.
//

#include "resistor.h"

#include <utility>


resistor::resistor(int x, std::string y){
    resistance = x;
    smd_size = std::move(y);
}
//Function that calculated the needed resistance base on a power_in object and a consumer
int resistor::rescalc(const power_in& usb, int consumer){
    resistance = (usb.voltage-consumer)*usb.amperage;
    return resistance;
}

std::ostream &operator<<(std::ostream &os, const resistor &resistor) {
    os << "resistance: " << resistor.resistance << " smd_size: " << resistor.smd_size;
    return os;
}