#include "../header/Sensor.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

namespace temp{

    Sensor::Sensor(string sensorName, string sensorPath)
    {
        name = sensorName;
        path = sensorPath;
    }

    int Sensor::getTemperature()
    {
        ifstream HeatFile(path + "/temp");
        getline (HeatFile, heat);
        HeatFile.close();

        return stoi(heat);
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