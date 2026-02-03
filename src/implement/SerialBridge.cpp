#include "../header/SerialBridge.hpp"
#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

namespace serial{

    SerialBridge::SerialBridge(string deviceName)
    {
        this->deviceName = deviceName;
        picoConnection.open("/dev/ttyACM0");
    }

    void SerialBridge::sendData(string message)
    {
        picoConnection << message + "\n";
        picoConnection.flush();
    }
}