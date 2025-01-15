#ifndef METHOD1D_H
#define METHOD1D_H
#include "Mesh1D.h"

#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>
#include <memory>

class Method1D{
public:
    virtual ~Method1D() = default;
    virtual std::vector<double> getSolution(std::vector<std::vector<double>>& matrixA,
                                            std::vector<double>& matrixB){
                                                return {};
                                            }
    // Для явных методов: выполняет итерационный шаг.
    virtual void getExplicitSolution() {
        std::cout<<"virtual void performExplicitStep(double timeStep)\n";
    }
protected:
    Mesh1D* mesh;
    std::unordered_map<std::string, double> paramtersOfTask;
    std::vector<double> solution;
    std::vector<std::vector<double>> solutionT;

};

#endif
