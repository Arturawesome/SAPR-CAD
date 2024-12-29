#ifndef METHOD1D_H
#define METHOD1D_H
#include "Mesh1D.h"

#include <unordered_map>

class Method1D:{
public:
    virtual ~Method1D() default;
    virtual getSolution() = 0;
protected:
    Mesh1D mesh;
    std::unordered_map<std::string, double> paramtersOfTask;
    std::vector<double> solution;


}

#endif
