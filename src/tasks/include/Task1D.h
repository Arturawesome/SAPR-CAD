#ifndef TASK1D_H
#define TASK1D_H

#include "Method1D.h"
#include "Mesh1D.h"
#include<unordered_map>
class Task1D:{
protected:
    Method1D *method1d
    Mesh1D *mesh1d
    std::unordered_map<std::string, double> paramtersOfTask;
    int dimension;

public:
    ~Task1D( Method1D *method, Mesh1D *mesh): method1d(method), mesh1d(mesh) ;
    virtual SetParameters(std::string typeTask,int dim, std::unordered_map<std::string, double> paramtersOfTask) = 0;
    virtual solveTask(Method1D method1d, Mesh1D mesh1d) = 0;

};

#endif
