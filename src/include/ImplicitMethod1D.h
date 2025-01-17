#ifndef IMPLICITMETHOD1D_H
#define IMPLICITMETHOD1D_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>
#include <memory>

class ImplicitMethod1D{
public:
    virtual ~ImplicitMethod1D() = default;
    virtual getSolution() = 0;
    virtual setMatrix() {}
    virtual setMatrixT() {}

protected:
    std::vectro<std::vecotor<double>> matrixA_;
    std::vectro<std::vecotor<double>> matrixBT_;
    std::vecotor<double> matrixB_;

    std::vector<double> solution_;
    std::vectro<std::vecotor<double>> solutionT_;
};



#endif
