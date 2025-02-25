#ifndef METHOD1D_H
#define METHOD1D_H
#include "Mesh1D.h"

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

class Method1D
{
  public:
    virtual ~Method1D() = default;
    virtual std::vector<double>
    getSolution(std::vector<std::vector<double>>& matrixA,
                std::vector<double>& matrixB)
    {
        return {};
    }

    virtual std::vector<std::vector<double>> getExplicitSolution() {}
    virtual void setInitialConditions() {}
    virtual void numericalScheme(int ts) {}

  protected:
    Mesh1D* mesh;
    std::unordered_map<std::string, double> paramtersOfTask;
    std::vector<double> solution;
    std::vector<std::vector<double>> solutionT_;
    int sizeMeshx_;
    int sizeMesht_;
};

#endif
