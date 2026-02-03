#include "../header/MemoryGrabber.hpp"
#include <fstream>
#include <string>

using namespace std;

namespace mem{

    string MemoryGrabber::getSystemMemory()
    {
        this->getAvailableMemory();
        this->readTempFile();
        return memory;
    }

    void MemoryGrabber::getAvailableMemory()
    {
        system("cat /proc/meminfo | grep -E 'MemTotal|MemAvailable' | rev | cut -f2 -d' ' | rev > tmp.txt");
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