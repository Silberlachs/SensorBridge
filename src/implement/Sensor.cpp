#include "../header/Sensor.hpp"

using namespace std;

namespace temp{

    Sensor::Sensor(string sensorName, string sensorPath)
    {
        name = sensorName;
        path = sensorPath;
    }

    int Sensor::getTemperature()
    {
        return temperature;
    }

    string Sensor::getName()
    {
        return name;
    }

    string Sensor::getPath()
    {
        return path;
    }

    void Sensor::updateTemperature(int updateVal)
    {
        temperature = updateVal;
    }

}