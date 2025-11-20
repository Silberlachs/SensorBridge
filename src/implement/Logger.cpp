#include <fstream>
#include <iostream>
#include <chrono>
#include "../header/Logger.hpp"

using std::ofstream;
using namespace std::chrono;

namespace logging
{
    void Logger::logToFile(std::string msg)
    {
        ofstream out;
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string s(19, '\40');
        std::strftime(&s[0], s.size(), "[%d.%m.%Y %H:%M] ", std::localtime(&now));

        out.open ("../../log/logFile.txt",std::ios_base::app); //append mode
        out << s << msg << "\n";
        out.close();
    }
}