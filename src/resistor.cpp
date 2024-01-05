//
// Created by Beaver on 11/22/2023.
//

#include "../headers/resistor.h"

#include <utility>


[[maybe_unused]] resistor::resistor(int resistance, std::string smd_size):resistance(resistance), smd_size(std::move(smd_size)){}

//Function that calculated the needed resistance base on a power_in object and a consumer
[[maybe_unused]] int resistor::rescalc(const power_in<int>& usb, int consumer){
    resistance = (usb.voltage-consumer)*usb.amperage;
    return resistance;
}

std::ostream &operator<<(std::ostream &os, const resistor &resistor) {
    os << "resistance: " << resistor.resistance << " smd_size: " << resistor.smd_size;
    return os;
}