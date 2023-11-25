//
// Created by Beaver on 11/23/2023.
//

#include "diode.h"
#include "iostream"
#include <utility>


diode::diode(std::string smdSize) : smdSize(std::move(smdSize)) {}

std::ostream &operator<<(std::ostream &os, const diode &diode) {
    os << "smd_size: " << diode.smdSize << " fw_voltage: " << diode.fwVoltage << " fw_amperage: "
       << diode.fwCurrent;
    return os;
}

//Function that calculates the Power consumed by the diode
float diode::PowerSum() const{
    return fwVoltage * fwCurrent;
}


zener_diode::zener_diode(const std::string &smdSize, float bwVoltage, float bwAmperage)
        : diode(smdSize), bw_voltage(bwVoltage), bw_amperage(bwAmperage) {}




LED::LED(const std::string &smdSize) : diode(smdSize), color("none") {}

std::ostream &operator<<(std::ostream &os, const LED &led) {
    os << static_cast<const diode &>(led) << " color: " << led.color;
    return os;
}
//Function that calculates the Power consumed by the LED

float LED::PowerSum() const {
    const float fixedCurrent = 0.02;
    return fwVoltage * fixedCurrent;
}

//Function that lets you select the color of the LED, also setting the voltage needed for the LED.
void LED::set_led(){
    std::cout<<"\nPlease select the color of the led: \n1.White 2.Blue 3 .Red 4 .Green\n";
    int led_num;
    std::cin>>led_num;
    switch(led_num){
        case 1:
            fwVoltage = 4;
            color = "white";
            break;
        case 2:
            fwVoltage = 3;
            color = "blue";
            break;
        case 3:
            fwVoltage = 1.8;
            color = "red";
            break;
        case 4:
            fwVoltage = 3;
            color = "green";
            break;
        default:
            throw std::logic_error ("Option not available :(");
    }
}




Photodiode::Photodiode(const std::string &smdSize, std::string material) : diode(smdSize), material(std::move(material)) {}
