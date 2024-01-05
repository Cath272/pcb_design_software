//
// Created by Beaver on 11/22/2023.
//

#include "../headers/caps.h"

#include <utility>

caps::caps(int capacitance, std::string size):capacitance(capacitance), size(std::move(size)){}


void caps::cap_select(){

    std::cout<<"Introduce the capacity of the capacitor:";
    std::cin>>capacitance;
    std::cout<<capacitance;

}

std::ostream &operator<<(std::ostream &os, const caps &caps) {
    os << "capacitance: " << caps.capacitance << " size: " << caps.size;
    return os;
}