// Created by Beaver on 11/22/2023.
// Class declaration of the power_in class (power plug)

#ifndef OOP_POWER_IN_H
#define OOP_POWER_IN_H

#include <iostream>

template <typename T>
class power_in {
private:
    std::string plug_type;
    T voltage;
    T amperage;

public:
    power_in(std::string x, T y, T z);

    ~power_in();

    friend std::ostream& operator<<(std::ostream& output, const power_in<T>& PD) {
        output << "Port : " << PD.plug_type << " Tension : " << PD.voltage << "V " << PD.amperage << "A";
        return output;
    }

    friend class resistor;

    void port_select();
};

#endif //OOP_POWER_IN_H

