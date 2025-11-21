#ifndef TEMPERATURGRABBER_HPP
#define TEMPERATURGRABBER_HPP
#include <string>
#include <vector>
#include <variant>
#include <sys/stat.h>
#include "Sensor.hpp"
using namespace std;

namespace temp{
    class TemperatureGrabber
    {
        private:
            bool isFileAvailable();
            string path;
            int sensorCount = 0;            // number of loops through folder
            vector<Sensor*> sensors;
            struct stat sb;

        public:
            TemperatureGrabber(std::string);
    };
}
#endif
