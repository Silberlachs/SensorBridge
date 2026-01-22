#!/bin/bash

groups="$(groups $USER)"
if echo "$groups" | grep -q "dialout";
then
    cd ./src/implement/
    g++ main.cpp TemperatureGrabber.cpp MemoryGrabber.cpp Logger.cpp Sensor.cpp SerialBridge.cpp -o ../../bin/TempGrabber
    cd ../../
    ./bin/TempGrabber
else
    echo "ERROR: Pls add your user to dialout group for Microcontroller communication!\n(Don't forget to log off and on afterwards)"
fi