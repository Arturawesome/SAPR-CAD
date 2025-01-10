#ifndef LAXWENDROFFMETHOD1D_H
#define LAXWENDROFFMETHOD1D_H
#include "Method1D.h"

#include <unordered_map>
#include <vector>

class LaxWendroffMethod1D: public Method1D{
public:
    LaxWendroffMethod1D();
    virtual std::vector<double> getSolution( std::vector<std::vector<double>>& matrixA, std::vector<double>& matrixB) override;

private:
    std::vector<std::vector<double>> matrixA;
    std::vector<double> matrixB;

};



#endif
