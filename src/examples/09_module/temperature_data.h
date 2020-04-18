//temperature_data.h
#include "temperature.h"
#ifndef TEMPERATURE_DATA_H
#define TEMPERATURE_DATA_H

#include<vector>
#include<string>

class TemperatureData
{
public:
    void save_temps(std::vector<Temperature>& ts);
    std:vector<Temperature> get_temps()const;
    
private:
    std::vector<Temperature> temps;
    const std::string file_name{"temperature.dat"};
};

#endif
