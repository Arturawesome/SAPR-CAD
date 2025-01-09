#ifndef TASK1D_H
#define TASK1D_H

#include "matplotlibcpp.h"
#include "Method1D.h"
#include "Mesh1D.h"

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
namespace plt = matplotlibcpp;

class Task1D{
protected:
    std::unique_ptr<Method1D> method;
    std::unique_ptr<Mesh1D> mesh;
    std::unordered_map<std::string, std::string> paramtersOfTask;

    std::vector<std::vector<double>> matrixA;
    std::vector<double> matrixB;

    bool useCustomMesh = false;
    bool useCustomMethod = false;

    double time = -1, dt = -1;
    bool isStatic = true;

    double N = 1;
    int dimension;

    std::vector<double> solution;

public:
    virtual ~Task1D() = default;
    virtual void solveTask() = 0;
    virtual void getTaskDescription() = 0;
    virtual void setMatrixAndConditions() = 0;
    virtual void plotSolution(std::string nameFig) = 0;


};

#endif
