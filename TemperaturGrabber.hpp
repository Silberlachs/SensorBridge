#ifndef TEMPERATURGRABBER_HPP
#define TEMPERATURGRABBER_HPP
#include <string>
#include <vector>
#include <sys/stat.h>

namespace temp{
    class TemperaturGrabber
    {
        std::string path;
        private:
            bool isFileAvailable();
            int sensorCount = 0;            // number of loops through folder
            std::vector<int[2]> myVector();
            struct stat sb;

        public:
            TemperaturGrabber(std::string);
    };
}
#endif
