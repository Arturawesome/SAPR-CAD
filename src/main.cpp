#include <iostream>

#include "LinearMesh1D.h"
#include "HeatTask1D.h"
#include "FiniteDifferenceMethod1D.h"

int main() {


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
    task.solveTask();

    return 0;
}
