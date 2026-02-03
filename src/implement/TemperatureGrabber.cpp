#include "../header/TemperatureGrabber.hpp"
#include "../header/Sensor.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

namespace temp{

/*  At creation time, check how many cooling devices are found
    and read a sample value from them to initialize data structure
    To do so, simply loop through temperature_zone indices until -1
    TODO: currently OS assumed: ubuntu                              */
    TemperatureGrabber::TemperatureGrabber(string path)
    {
        this->path = path;
        while(true)
        {
            if (isFileAvailable())
            {
                string heat, heatname;
                string zoneStr = (path + to_string(sensorCount) + (string)"/").c_str();

                ifstream HeatFile(zoneStr + "/temp");
                ifstream HeatNameFile(zoneStr + "/type");

                getline (HeatFile, heat);
                getline (HeatNameFile, heatname);

                Sensor *sensor = new Sensor(heatname, zoneStr);
                sensor->updateTemperature(stoi(heat));
                sensors.push_back(sensor);

                HeatFile.close();
                HeatNameFile.close();
            }
            else
            {
                break;
            }
            sensorCount++;
        }
    }

    /* checks whether file with temperature information is available */
    bool TemperatureGrabber::isFileAvailable()
    {
        return (stat((path + to_string(sensorCount) + (string)"/").c_str() , &sb) == 0);
    }

    string TemperatureGrabber::getSensoryDataInit()
    {
        string payload;
        for(int l=0; l< sensors.size(); l++)
        {
            payload = payload + sensors[l]->getName() + "#";
        }
        return payload;
    }

    string TemperatureGrabber::getSensoryData()
    {
        string payload;
        for(int l=0; l< sensors.size(); l++)
        {
            payload = payload + to_string(sensors[l]->getTemperature()/1000) + "#";
        }
        return payload;
    }
}