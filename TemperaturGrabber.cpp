#include "TemperaturGrabber.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>
#include <string>

namespace temp{
    TemperaturGrabber::TemperaturGrabber(std::string path)
    {
        this->path = path;
        struct stat sb;

        fprintf(stdout, "checking for Temperature Sensors...\n");

        //DEBUG: is folder available?
        //fprintf(stdout,"string is %d", stat((path + std::__cxx11::to_string(0) + (std::string)"/").c_str() , &sb) );

        if (stat((path + std::__cxx11::to_string(0) + (std::string)"/").c_str() , &sb) == 0)
        {
            fprintf(stdout,"welp"); // folder found -> save path to array
            // sys/class/thermal/thermal_zone0/temp
            // sys/class/thermal/thermal_zone0/type
        }

        if(checkFileAvailable())
        {
            fprintf(stdout, "sensors available!");
        }
    }

    int TemperaturGrabber::checkFileAvailable()
    {
        return 1;
    }
}