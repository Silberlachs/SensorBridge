#ifndef MEMORYGRABBER_HPP
#define MEMORYGRABBER_HPP
#include <string>

using namespace std;

namespace mem{

    class MemoryGrabber
    {
        private:
            string tmp, memory;
            void sendSystemCall();
            string readTempFile();

        public:
            string getSystemMemory();
    };

}

#endif