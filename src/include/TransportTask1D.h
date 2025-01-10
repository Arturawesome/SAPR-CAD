#ifndef TRANSPORTTASK1D_H
#define TRANSPORTTASK1D_H

#include "Task1D.h"
#include "LinearMesh1D.h"
#include "FiniteDifferenceMethod1D.h"

class TransportTask1D: public Task1D{
public:
    TransportTask1D(std::unordered_map<std::string, std::string> param);
    virtual void solveTask() override;
    virtual void getTaskDescription() override;
    virtual void plotSolution(std::string nameFig) override;


private:
    double transferSpeed;
    double leftBC, rightBC;
    int initialC;
    bool isTransferSpeedConst;

};


#endif
