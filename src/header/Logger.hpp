#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

namespace logging{
    class Logger
    {
        public:
            static Logger* getInstance()
            {
                if (instance = nullptr)
                {
                    instance = new Logger();
                }
                return instance;
            }

            void logToFile(std::string msg);

        private:
            Logger() {}
            static Logger* instance;

            //important for singleton pattern
            Logger(Logger const&);              // Don't Implement
            void operator=(Logger const&);      // Don't implement
    };
}
#endif