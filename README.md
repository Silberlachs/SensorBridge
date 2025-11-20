This project aims to build a serial bridge to a raspberry pico 2 device.
This is the "backend", running on an Ubuntu machine.
This program will periodically check cooling devices and read sensor data,
sending them to the Raspberry. 

The project currently has milestones set on temperature data, RAM and cpu usage.
I will keep this repository updated during developement.

Things to consider: 
- Multithreading
- communication protocoll (at least for initial connection)
- transfer data capsules containing all sensor data at once to save resources


Just call sh buildRun.sh to automatically translate and run the program.
This will result in the following script beeing executed:

``
#!/bin/sh

cd ./src/implement/
g++ main.cpp TemperaturGrabber.cpp Logger.cpp -o ../../bin/TempGrabber
cd ../../
./bin/TempGrabber
``