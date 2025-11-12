// io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20

#include <iostream>
#include <iomanip>
#include <fstream>
#include "TemperaturGrabber.hpp"
#include "Logger.hpp"

using namespace std;
using temp::TemperaturGrabber;
using logging::Logger;

Logger* Logger::instance = nullptr;

int main() {

    TemperaturGrabber* temp = new TemperaturGrabber("/sys/class/thermal/thermal_zone");
    Logger* logger = Logger::getInstance();
    logger->logToFile("this is a triumph");

    // 1: probe how many underfolders under thermal_zone are
    // 2: read temp and type files of each
    // 3: output data to display RPI
    // 4: create a custom font

    ifstream inFile;
    inFile.open("/sys/class/thermal/thermal_zone0/temp");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    free(logger);
    inFile.close();
    return 0;
}