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
    float  fwVoltage  = 0.6;
    float  fwCurrent{};
public:
    friend std::ostream &operator<<(std::ostream &os, const diode &diode);
    explicit diode(std::string smdSize);

    [[nodiscard]] virtual float PowerSum() const;
};

class zener_diode  : diode{
//Zener_diode (subclass of Diode) - allows the flow of current "backwards"
    float  bw_voltage;
    float  bw_amperage;
public:
    zener_diode(const std::string &smdSize, float bwVoltage, float bwAmperage);

};

class LED  : diode{
//Light emitting diode (subclass of Diode) - emits light when current flows through  it
    std::string color;

public:
    explicit LED(const std::string &smdSize);


    friend std::ostream &operator<<(std::ostream &os, const LED &led);
    void  set_led();
     [[nodiscard]] float PowerSum() const override;


};

class Photodiode  : diode{
//Photodiode - produces current when it absorbs photons
 std::string material;
public:
    Photodiode(const std::string &smdSize, std::string material);
};


#endif //OOP_DIODE_H
