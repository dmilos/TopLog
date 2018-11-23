#!/bin/bash

reset
pwd
g++ -fexceptions -std=c++11 -g -I../src TopLog.cpp               -o  TopLog

g++ -fexceptions -std=c++11 -g -I../src step_1.cpp -o step_1
g++ -fexceptions -std=c++11 -g -I../src step_2.cpp -o step_2
g++ -fexceptions -std=c++11 -g -I../src step_3.cpp -o step_3
g++ -fexceptions -std=c++11 -g -I../src step_4.cpp -o step_4
