#ifndef TASK1D_H
#define TASK1D_H

#include "Method1D.h"
#include "Mesh1D.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
class Task1D{
protected:
    std::unique_ptr<Method1D> method;
    std::unique_ptr<Mesh1D> mesh;
    std::unordered_map<std::string, std::string> paramtersOfTask;
    int dimension;

public:
    virtual ~Task1D() = default;
    virtual void solveTask() = 0;
    virtual void getTaskDescription() = 0;


};

#endif
