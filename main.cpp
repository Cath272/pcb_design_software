#include <iostream>
#include "headers/caps.h"
#include "headers/resistor.h"
#include "headers/power_in.h"
#include "headers/diode.h"
#include "sfml/graphics.h"
using namespace std;



int main() {



    power_in<float> usb3 ("usb_c", 5, 1.2);
    cout<<usb3<<"\n";
    power_in<int> usb2 ("usb_c", 5, 1);
    cout<<usb2;
    OpenWindow();

    /*
    resistor res1(120, "0805");
    vector<std::string> components_list;
    int comp_num;
    std::string aux;

    //Pointers to PowersSum function
    diode diode1("0805");
    cout<<diode1;
    LED led1("0805");
    led1.set_led();
    cout<<led1;
    diode* diode1Pointer;
    diode1Pointer = &diode1;
    LED* led1Pointer;
    led1Pointer = &led1;

    cout<<"\n"<<diode1Pointer->PowerSum();
    cout<<"\n"<<led1Pointer->PowerSum();


    LED led2("0805");


    //set_led exception test
    try {
        led2.set_led();
    }
    catch(std::logic_error& h){
        std::cerr << h.what() <<endl;
        return -1;
    }
    //Port_select exception test
    try {
        usb3.port_select();
    }
    catch(std::logic_error& e){
        std::cerr << e.what() <<endl;
        return -1;
    }
    std::cout<<"how many components do you need?";
    std::cin>>comp_num;
    for(int i = 0; i< comp_num; i++){
        std::cin>>aux;
        components_list.push_back(aux);
    }
    res1.rescalc(usb3, 2);
    caps cap1(20, "0450");
    cap1.cap_select();
    return 0;
    */
}
