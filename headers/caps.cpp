//
// Created by Beaver on 11/22/2023.
//

#include "caps.h"

#include <utility>

caps::caps(int x, std::string y){
    capacitance = x;
    size = std::move(y);
}

void caps::cap_select(){

    std::cout<<"Introduce the capacity of the capacitor:";
    std::cin>>capacitance;
    std::cout<<capacitance;

}

std::ostream &operator<<(std::ostream &os, const caps &caps) {
    os << "capacitance: " << caps.capacitance << " size: " << caps.size;
    return os;
}