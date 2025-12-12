#ifndef SERIALBRIDGE_HPP
#define SERIALBRIDGE_HPP
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

namespace serial{

    class SerialBridge
    {
        public:
            SerialBridge(string);
            int openConnection(void);
            void sendData(string);

        private:
            string deviceName;
            fstream picoConnection;
    };
}

#endif