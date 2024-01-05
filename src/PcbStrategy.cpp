//
// Created by Beaver on 05/01/2024.
//

#include "../headers/PcbStrategy.h"
#include <iostream>

void SmallPCB::produce(const std::string& size, const std::string& color) {
    std::cout << "Produced a small PCB of size " << size << " and color " << color << ".\n";
}

void MediumPCB::produce(const std::string& size, const std::string& color) {
    std::cout << "Produced a medium PCB of size " << size << " and color " << color << ".\n";
}

void LargePCB::produce(const std::string& size, const std::string& color) {
    std::cout << "Produced a large PCB of size " << size << " and color " << color << ".\n";
}

void PCBFactory::setPCBStrategy(PCBStrategy* strategy) {
    pcbStrategy = strategy;
}

void PCBFactory::manufacture(const std::string& size, const std::string& color) {
    if (pcbStrategy) {
        pcbStrategy->produce(size, color);
    } else {
        std::cout << "Please set a PCB production strategy before manufacturing.\n";
    }
}

