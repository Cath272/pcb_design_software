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

    return 0;
}
