#ifndef TEMPERATURGRABBER_HPP
#define TEMPERATURGRABBER_HPP
#include <string>

namespace temp{
    class TemperaturGrabber
    {
        std::string path;
        private:
            int checkFileAvailable();
            int sensorCount = 0;

        public:
            TemperaturGrabber(std::string);
    };
}
#endif
