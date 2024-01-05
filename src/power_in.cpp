//
// Created by Beaver on 11/22/2023.
//
#include "../headers/power_in.h"
#include <utility>
#include <iostream>

// Define power_in as a template class
template <typename T>
power_in<T>::power_in(std::string x, T y, T z) : plug_type(std::move(x)), voltage(y), amperage(z) {}


template <typename T>
power_in<T>::~power_in() {
    std::cout << "\n Powering off";
}



// Function that lets you select the port type
template <typename T>
void power_in<T>::port_select() {
    std::cout << "Please Select one of the following ports: \n 1.USB C \n 2.Micro USB \n 3.DC Barrel Jack \n";
    int usb_num;
    std::cin >> usb_num;
    switch (usb_num) {
        case 1:
            std::cout << "USB C selected \n";
            plug_type = "usc_C";
            break;
        case 2:
            std::cout << "Micro USB selected \n";
            plug_type = "micro_usb ";
            break;
        case 3:
            std::cout << "DC Barrel Jack selected \n";
            plug_type = "DC_jack";
            break;
        default:
            throw std::logic_error("Option not available :'(");
    }
}

// Explicit instantiation for int (you can add more instantiations if needed)
template class power_in<int>;
template class power_in<float>;

template class power_in<double>;