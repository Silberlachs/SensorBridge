#include <iostream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "../header/TemperatureGrabber.hpp"
#include "../header/Logger.hpp"
#include "../header/SerialBridge.hpp"
#include "../header/MemoryGrabber.hpp"

using namespace std;
using temp::TemperatureGrabber;
using logging::Logger;
using serial::SerialBridge;
using mem::MemoryGrabber;

Logger* Logger::instance = nullptr;

int main() {

    //TODO: write some automated tests (will be necessary to pass some mock objects )
    TemperatureGrabber* temp = new TemperatureGrabber("/sys/class/thermal/thermal_zone");
    MemoryGrabber* mem = new MemoryGrabber();
    Logger* logger = Logger::getInstance();

    ifstream inFile;
    inFile.open("/sys/class/thermal/thermal_zone0/temp");
    if (!inFile) {
        logger->logToFile("Unable to open default thermal_zone file.");
        exit(1); // terminate with error
    }

    SerialBridge* serialBridge = new SerialBridge("/dev/ttyACM0");

    //setting screen values : $:CATEGORYNAME
    string payload = "$:TEMP#";
    payload += temp->getSensoryDataInit();  //name of entries

    payload += "$:RAM#";
    payload += " #&:gauge"; //unnamed entry, then special type
    serialBridge->sendData(payload.c_str());

//at this point initialization has finished and we can update data

    while(true){

        payload = temp->getSensoryData();
        payload += mem->getSystemMemory();
        serialBridge->sendData(payload.c_str());
        std::this_thread::sleep_for(3500ms);
    }

    free(logger);
    free(serialBridge);
    inFile.close();
    return 0;
}