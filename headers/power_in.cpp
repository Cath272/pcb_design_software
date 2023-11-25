//
// Created by Beaver on 11/22/2023.
//

#include "power_in.h"

#include <utility>

power_in::power_in( std::string x, int y, int z): plug_type(std::move(x)),voltage(y),amperage(z){}

power_in::power_in(const power_in& usb)
{
    plug_type = usb.plug_type;
    voltage = usb.voltage;
    amperage = usb.amperage;
}
power_in::~power_in(){
    std::cout<<"\n Powering off";
}

std::ostream &operator<<( std::ostream &output, const power_in &PD ) {
    output << "Port : " << PD.plug_type << " Tensiune : " << PD.voltage<< "V "<< PD.amperage<< "A";
    return output;
}
//Function that lets you select the port type
void power_in::port_select(){
    std::cout<<"Please Select one of the following ports: \n 1.USB C \n 2.Micro USB \n 3.DC Barrel Jack \n";
    int usb_num;
    std::cin>>usb_num;
    switch (usb_num) {
        case 1:
            std::cout<<"USB C selected \n";
            plug_type = "usc_C";
            break;
        case 2:
            std::cout<<"Micro USB selected \n";
            plug_type = "micro_usb ";
            break;
        case 3:
            std::cout<<"DC Barrel Jack selected \n";
            plug_type = "DC_jack";
            break;
        default:
            throw std::logic_error ("Option not available :'(");
    }

}