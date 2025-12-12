#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "../header/TemperatureGrabber.hpp"
#include "../header/Logger.hpp"
#include "../header/SerialBridge.hpp"

using namespace std;
using temp::TemperatureGrabber;
using logging::Logger;
using serial::SerialBridge;

Logger* Logger::instance = nullptr;


string getMemoryInfo(void)
{
    string tmp,memory;
    memory = "";

    try{
        system("cat /proc/meminfo | grep -E 'MemTotal|MemAvailable' > tmp.txt");
        ifstream in("tmp.txt");	

        getline(in,tmp);
        memory = tmp;
        getline(in,tmp);
        memory += "#";
        memory += tmp;
        in.close();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';      //use logger here
    }


    return memory;
}

int main() {

    TemperatureGrabber* temp = new TemperatureGrabber("/sys/class/thermal/thermal_zone");
    Logger* logger = Logger::getInstance();

    ifstream inFile;
    inFile.open("/sys/class/thermal/thermal_zone0/temp");
    if (!inFile) {
        logger->logToFile("Unable to open default thermal_zone file.");
        exit(1); // terminate with error
    }

    SerialBridge* serialBridge = new SerialBridge("/dev/ttyACM0");
    serialBridge->openConnection();
    serialBridge->sendData("1911"); //implement protocoll
    string payload = temp->getSensoryDataInit();

    payload += getMemoryInfo();
    serialBridge->sendData(payload.c_str());

//at this point initialization has finished and we can update data

    while(true){

        payload = temp->getSensoryData();
        payload += getMemoryInfo();
        serialBridge->sendData(payload.c_str());
        std::this_thread::sleep_for(3500ms);
    }

    free(logger);
    free(serialBridge);
    inFile.close();
    return 0;
}