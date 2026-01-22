#include "../header/SerialBridge.hpp"
#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

namespace serial{

    SerialBridge::SerialBridge(string deviceName)
    {
        this->deviceName = deviceName;
    }

    void SerialBridge::setSecret(int secretNum)
    {
        this->secretNum = secretNum;
    }

    int SerialBridge::openConnection()
    {
        picoConnection.open("/dev/ttyACM0");
        picoConnection << "1910#" << std::to_string(this->secretNum) << "\n";
        picoConnection.flush();

        return 0;
    }

    void SerialBridge::sendData(string message)
    {
        picoConnection << std::to_string(1910 + this->secretNum) << "#" << message + "\n";
        picoConnection.flush();
    }
}