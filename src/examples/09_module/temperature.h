//temperature.h
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

//function code
class Temperature
{
public:
    Temperature(int h, int r) : hour(h), reading(r) {}
    int get_reading() const{return reading; };
    int get_hour() const { return hour;};

private:
    int hour;
    double reading;
};

#endif
