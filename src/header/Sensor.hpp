#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
using namespace std;

namespace temp{
    class Sensor
    {
        public:
            Sensor(string);
            void updateTemperature(int);
            int getTemperature(void);
            string getName(void);

        private: 
            string name;
            int temperature;
    };
}
#endif