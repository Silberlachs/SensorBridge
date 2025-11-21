#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/TemperatureGrabber.hpp"
#include "../header/Logger.hpp"

using namespace std;
using temp::TemperatureGrabber;
using logging::Logger;

Logger* Logger::instance = nullptr;

int main() {

    TemperatureGrabber* temp = new TemperatureGrabber("/sys/class/thermal/thermal_zone");
    Logger* logger = Logger::getInstance();

    // 1: probe how many underfolders under thermal_zone are    [DONE]
    // 2: read temp and type files of each                      [DONE]
    // 3: output data to display RPI
    // 4: create a custom font

    ifstream inFile;
    inFile.open("/sys/class/thermal/thermal_zone0/temp");
    if (!inFile) {
        logger->logToFile("Unable to open default thermal_zone file. Is this Ubuntu?");
        exit(1); // terminate with error
    }

    free(logger);
    inFile.close();
    return 0;
}