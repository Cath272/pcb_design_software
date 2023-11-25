//
// Created by Beaver on 11/22/2023.
//Class declaration of the power_in class (power plug)

#ifndef OOP_POWER_IN_H
#define OOP_POWER_IN_H

#include <iostream>

class power_in {
    std::string plug_type;
    int voltage;
    int amperage;
public:
    power_in( std::string x, int y, int z);
    power_in(const power_in& usb);
    ~power_in();
    friend std::ostream &operator<<( std::ostream &output, const power_in &PD );
    friend class resistor;
    void port_select();
};



#endif //OOP_POWER_IN_H
