#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
using namespace std;

namespace temp{
    class Sensor
    {
        public:
            Sensor(string, string);
            void updateTemperature(int);
            int getTemperature(void);
            string getName(void);
            string getPath(void);

        private: 
            string name, path, heat;
            int temperature;
    };
}
#endif