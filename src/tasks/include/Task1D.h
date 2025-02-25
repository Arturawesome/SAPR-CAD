#ifndef TASK1D_H
#define TASK1D_H

#include "Mesh1D.h"
#include "Method1D.h"
#include "matplotlibcpp.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
namespace plt = matplotlibcpp;

class Task1D
{
  protected:
    std::shared_ptr<Method1D> method_;
    std::shared_ptr<Mesh1D> mesh_;
    std::shared_ptr<Mesh1D> meshT_;
    std::unordered_map<std::string, std::string> paramtersOfTask_;

    std::vector<std::vector<double>> matrixA;
    std::vector<double> matrixB;

    bool useCustomMesh = false;
    bool useCustomMethod = false;

    double time = -1, dt = -1;
    bool isStatic_ = true;

    double N = 1;
    double Nt = 1;
    double Nx = 1;
    double L = 1;
    int dimension;
    double courantNumber = 0;

    std::vector<double> solution;
    std::vector<std::vector<double>> solutionT_;

  public:
    virtual ~Task1D() = default;
    virtual void solveTask() = 0;
    virtual void getTaskDescription() = 0;
    virtual void plotSolution(std::string nameFig) = 0;
    virtual void saveTask() {}
};

#endif
