#ifndef TASK1D_H
#define TASK1D_H

#include "Method1D.h"
#include "Mesh1D.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
class Task1D{
protected:
    Method1D *method;
    Mesh1D *mesh;
    std::unordered_map<std::string, std::string> paramtersOfTask;
    int dimension;

public:
    virtual ~Task1D() = default;
    virtual void solveTask() = 0;
    virtual void getTaskDescription() = 0;

};

#endif
