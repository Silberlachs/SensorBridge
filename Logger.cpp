#include <fstream>
#include <iostream>
#include "Logger.hpp"

using std::ofstream;

namespace logging
{
    void Logger::logToFile(std::string msg)
    {
        ofstream out;
        out.open ("logFile.txt",std::ios_base::app); //append mode
        out << msg << "\n";
        out.close();
    }
}