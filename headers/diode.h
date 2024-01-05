//
// Created by Beaver on 11/23/2023.
//Class declarations of different diode types

#ifndef OOP_DIODE_H
#define OOP_DIODE_H


#include <ostream>

class diode {
// Base Diode class

protected:
    std::string  smdSize;
    double  fwVoltage  = 0.6;
    double  fwCurrent{};
public:
    friend std::ostream &operator<<(std::ostream &os, const diode &diode);
    explicit diode(std::string smdSize);

    [[maybe_unused]] [[nodiscard]] virtual double PowerSum() const;
};

class zener_diode  : public diode{
//Zener_diode (subclass of Diode) - allows the flow of current "backwards"
    double  bw_voltage;
    double  bw_amperage;
public:
    zener_diode(const std::string &smdSize, double bwVoltage, double bwAmperage);

    friend std::ostream &operator<<(std::ostream &os, const zener_diode &diode);

};

class LED  : public diode{
//Light emitting diode (subclass of Diode) - emits light when current flows through  it
    std::string color;

public:
    explicit LED(const std::string &smdSize);


    friend std::ostream &operator<<(std::ostream &os, const LED &led);
    void  set_led();
     [[nodiscard]] double PowerSum() const override;


};



#endif //OOP_DIODE_H
