#include "../header/MemoryGrabber.hpp"
#include <fstream>
#include <string>

using namespace std;

namespace mem{

    string MemoryGrabber::getSystemMemory()
    {
        this->sendSystemCall();
        this->readTempFile();
        return memory;
    }

    void MemoryGrabber::sendSystemCall()
    {
        system("cat /proc/meminfo | grep -E 'MemTotal|MemAvailable' > tmp.txt");
    }

    string MemoryGrabber::readTempFile()
    {
        memory = "";
        try{
            ifstream in("tmp.txt");	

            getline(in,tmp);
            memory = tmp;
            getline(in,tmp);
            memory += "#";
            memory += tmp;
            in.close();
        }
        catch(const std::exception& e){
            return "-1:ERROR";
        }
        return memory;
    }

}