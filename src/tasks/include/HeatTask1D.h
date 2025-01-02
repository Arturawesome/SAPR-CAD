#ifndef HEATTASK1D_H
#define HEATTASK1D_H

#include "Task1D.h"
#include "LinearMesh1D.h"
#include "FiniteDifferenceMethod1D.h"

class HeatTask1D: public Task1D{

public:
    HeatTask1D(std::unordered_map<std::string, std::string> param);
    virtual void solveTask() override;
    virtual void getTaskDescription() override;

private:

    bool useCustomMesh = false;
    bool useCustomMethod = false;


    double time = -1, dt = -1;
    bool isStatic = true;

    bool isInternalHeatSource  = false;
    double Xsource = -1, Ysource = -1;

    double Tleft = -1, Tright = -1;
    double alpha = -1;
    double N = 1, L = -1;

};

#endif






























