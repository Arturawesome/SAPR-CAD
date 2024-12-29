#ifndef HEATTASK1D_H
#define HEATTASK1D_H

#include"Task1D.h"

class HeatTask1D: public Task1D{
public:
    HeatTask1D()
    virtual SetParameters(std::string typeTask,int dim, std::unordered_map<std::string, double> paramtersOfTask) = 0;
    virtual solveTask(Method1D method1d, Mesh1D mesh1d) = 0;
private:
    std::unordered_map<std::string, double> paramtersOfTask;
    int dimension;

};

#endif
