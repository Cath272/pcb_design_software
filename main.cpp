#include <iostream>

using namespace std;

class smd_resistors{
public:
    int rezistenta;
    string smd_size;

    smd_resistors(int x, string y){
        rezistenta = x;
        smd_size = y;
    }

    friend ostream &operator<<(ostream &os, const smd_resistors &resistors) {
        os << "rezistenta: " << resistors.rezistenta << " smd_size: " << resistors.smd_size;
        return os;
    }

    int rescalc(int x, int y,int z){
        rezistenta = (x-y)*z;
        return rezistenta;
    }
};

class capacitors{
public:
    int capacitance;
    string size;
    capacitors(int x, string y){
        capacitance = x;
        size = y;
    }



    friend ostream &operator<<(ostream &os, const capacitors &capacitors) {
        os << "capacitance: " << capacitors.capacitance << " size: " << capacitors.size;
        return os;
    }
    void cap_select(){
        cout<<"Introduceti capacitatea condensatorului:";
        cin>>capacitance;

    }

};

class power_in{
public:
    string plug_type;
    int voltage;
    int amperage;
    power_in( string x, int y, int z){
        plug_type = x;
        voltage = y;
        amperage =z;
    }
    power_in(const power_in& usb)
    {
        plug_type = usb.plug_type;
        voltage = usb.voltage;
        amperage = usb.amperage;
    }
    ~power_in(){
        cout<<"\n Powering off";
    }
    friend ostream &operator<<( ostream &output, const power_in &PD ) {
        output << "Port : " << PD.plug_type << " Tensiune : " << PD.voltage<< "V "<< PD.amperage<< "A";
        return output;
    }

    void port_select(){
        cout<<"Please Select one of the following ports: \n 1.USB C \n 2.Micro USB \n 3.DC Barrel Jack \n";
        int usb_num;
        cin>>usb_num;
        switch (usb_num) {
            case 1:
                cout<<"USB C selected \n";
                plug_type = "usc_C";
                break;
            case 2:
                cout<<"Micro USB selected \n";
                plug_type = "micro_usb ";
                break;
            case 3:
                cout<<"DC Barrel Jack selected \n";
                plug_type = "DC_jack";
                break;
        }

    };

};



int main() {
    smd_resistors res1(47, "0805");
    capacitors cap1(1, "0805");
    power_in usb("usb_c", 5, 1);
    power_in usb2 = usb;
    usb2.plug_type = "micro_usb";
    cout<<usb<<"\n"<<usb2;

    cout<<"\n"<<res1.rescalc(usb.voltage, 3, usb.amperage)<<"ohm";
    usb.port_select();
    cap1.cap_select();

    return 0;

}
