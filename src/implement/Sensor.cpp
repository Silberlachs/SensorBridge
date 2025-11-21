#include "../header/Sensor.hpp"

using namespace std;

namespace temp{

    Sensor::Sensor(string sensorName)
    {
        name = sensorName;
    }

    int Sensor::getTemperature()
    {
        return temperature;
    }

    string Sensor::getName()
    {
        return name;
    }

    void Sensor::updateTemperature(int updateVal)
    {
        temperature = updateVal;
    }

}