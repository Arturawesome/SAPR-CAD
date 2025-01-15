#include <iostream>

#include "LinearMesh1D.h"
#include "HeatTask1D.h"
#include "FiniteDifferenceMethod1D.h"

#include "TransportTask1D.h"

int main() {

/*
    std::unordered_map<std::string, std::string> parameterOfTask = {
        //{"isStatic", "True"},
        //{"time", "0"},
        //{"dt", "0"},

        {"isInternalHeatSource", "False"},
        {"Xsource", "0"},
        {"Ysource", "0"},

        {"method", "FiniteDifferenceMethod1D"},

        {"meshType", "LinearMesh1D"},
        {"N", "15"},
        {"L", "1"},

        {"alpha", "25"},
        {"Tleft", "100"},
        {"Tright", "20"}
    };
    HeatTask1D task(parameterOfTask);
    task.getTaskDescription();
    task.solveTask(); */


    std::unordered_map<std::string, std::string> parameterOfTask2 = {
    {"method", "LaxWendroffMethod1D"},
    {"meshType", "LinearMesh1D"},

    {"L", "1"},
    {"Nx", "50"}, //N=L/dx
    {"time", "1.5"},
    {"Nt", "150"}, //M=T/dt

    {"isTransferSpeedConst", "true"},
    {"transferSpeed", "1"},
    {"leftBC", "0"},
    {"rightBC", "0"},
    {"initialCid", "0"}, // not parser -> choose the variance 1 - sin; 2 - sum of two gauss
    };
    TransportTask1D task2(parameterOfTask2);
    task2.getTaskDescription();
    task2.solveTask();

    return 0;
}
