#!/bin/sh

cd ./src/implement/
g++ main.cpp TemperatureGrabber.cpp Logger.cpp Sensor.cpp -o ../../bin/TempGrabber
cd ../../
./bin/TempGrabber