#include <iostream>
#include "headers/caps.h"
#include "headers/resistor.h"
#include "headers/power_in.h"
#include "headers/diode.h"
#include "sfml/graphics.h"
using namespace std;



int main() {



    power_in<double> usb3 ("usb_c", 5, 1.2);
    cout<<usb3<<"\n";
    power_in<int> usb2 ("usb_c", 5, 1);
    cout<<usb2;
    OpenWindow();




    resistor res1(120, "0805");
    res1.rescalc(usb2, 2);
    caps cap1(20, "0450");
    cap1.cap_select();
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
    return 0;

}
