#include <iostream>

#include "LinearMesh1D.h"
#include "HeatTask1D.h"
#include "FiniteDifferenceMethod1D.h"

int main() {
    LinearMesh1D proba1(5, 5);
    proba1.generateMesh();
    proba1.saveMesh("Mesh1d.txt");
    proba1.printMesh();

    FiniteDifferenceMethod1D numMethod;

    std::unordered_map<std::string, std::string> parameterOfTask = {
        {"isStatic", "True"},
        {"Time", "0"},
        {"dt", "0"},

        {"isInternalHeatSource", "False"},
        {"Xsource", "0"},
        {"Ysource", "0"},

        {"Method", "FiniteDifferenceMethod1D"},

        {"MeshType", "LinearMesh1D"},
        {"N", "5"},
        {"L", "1"},

        {"alpha", "25"},
        {"Tleft", "100"},
        {"Tright", "20"}
    };
    HeatTask1D task(parameterOfTask);


    return 0;
}
