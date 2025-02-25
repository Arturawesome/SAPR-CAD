#ifndef FINITEDIFFERENCEMETHOD1D_H
#define FINITEDIFFERENCEMETHOD1D_H

#include "Mesh1D.h"
#include "Method1D.h"
#include <iostream>

class FiniteDifferenceMethod1D : public Method1D
{
  public:
    FiniteDifferenceMethod1D();
    virtual std::vector<double>
    getSolution(std::vector<std::vector<double>>& matrixA,
                std::vector<double>& matrixB) override;

  private:
    std::vector<std::vector<double>> matrixA;
    std::vector<double> matrixB;
};

#endif
