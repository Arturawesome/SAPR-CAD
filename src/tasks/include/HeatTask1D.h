#ifndef HEATTASK1D_H
#define HEATTASK1D_H

#include "Task1D.h"


class HeatTask1D: public Task1D{
public:
    HeatTask1D(std::unordered_map<std::string, std::string> param);
    virtual void solveTask() override;
    virtual void getTaskDescription() override;

};

#endif
