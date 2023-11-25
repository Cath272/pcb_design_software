//
// Created by Beaver on 11/22/2023.
//Class declaration of capacitor class
#include <iostream>
#ifndef OOP_CAPS_H
#define OOP_CAPS_H


#include <ostream>

class caps {
    int capacitance;
    std::string size;


public:
    caps(int capacitance, std::string size);
    void cap_select();
    friend std::ostream &operator<<(std::ostream &os, const caps &caps);

};



#endif //OOP_CAPS_H
