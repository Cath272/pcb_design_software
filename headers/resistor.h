//
// Created by Beaver on 11/22/2023.
//Class declaration of resistor class

#ifndef OOP_RESISTOR_H
#define OOP_RESISTOR_H

#include <ostream>
#include "power_in.h"

class resistor {
    int resistance;
    std::string smd_size;

public:
    resistor(int x, std::string y);
    int rescalc(const power_in& usb, int consumer);
    friend std::ostream &operator<<(std::ostream &os, const resistor &resistor);
};


#endif //OOP_RESISTOR_H
