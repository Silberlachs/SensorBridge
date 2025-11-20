#include "../header/TemperaturGrabber.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

namespace temp{


/*  At creation time, check how many cooling devices are found
    and read a sample value from them to initialize data structure
    TODO: currently ubuntu assumed                                      */
    TemperaturGrabber::TemperaturGrabber(string path)
    {
        this->path = path;
        while(true)
        {

            if (isFileAvailable())
            {
                string myText, myText1;
                string zoneStr = (path + to_string(sensorCount) + (string)"/").c_str();

                ifstream MyFile(zoneStr + "/temp");
                ifstream MyFile1(zoneStr + "/type");

                getline (MyFile, myText);
                getline (MyFile1, myText1);
                cout << myText << endl;
                cout << myText1 << endl;

                MyFile.close();
            }
            else
            {
                break;
            }
            sensorCount++;
        }
    }

    bool TemperaturGrabber::isFileAvailable()
    {
        return (stat((path + to_string(sensorCount) + (string)"/").c_str() , &sb) == 0);
    }
}