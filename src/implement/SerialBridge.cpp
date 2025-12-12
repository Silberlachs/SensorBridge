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

    int SerialBridge::openConnection()  //TODO: add arguments for init, salt
    {
        picoConnection.open("/dev/ttyACM0");
        picoConnection << "#1910#1\n";        //don't forget \n symbol!!!
        picoConnection.flush();
        //picoConnection.close();

        return 0;
    }

    void SerialBridge::sendData(string message)
    {
        //picoConnection.open("/dev/ttyACM0");
        picoConnection << message + "\n";        //don't forget \n symbol!!!
        picoConnection.flush();
        //picoConnection.close();
    }
}