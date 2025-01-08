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
    virtual void setMatrixAndConditions() override;

private:

    bool isInternalHeatSource  = false;
    double Xsource = -1, Ysource = -1, Qsource;

    double Tleft = -1, Tright = -1;
    double alpha = -1;
    double L = -1;

};

#endif






























