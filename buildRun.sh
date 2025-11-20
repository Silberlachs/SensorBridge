#!/bin/sh

cd ./src/implement/
g++ main.cpp TemperaturGrabber.cpp Logger.cpp -o ../../bin/TempGrabber
cd ../../
./bin/TempGrabber