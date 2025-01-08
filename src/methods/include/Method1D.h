#ifndef METHOD1D_H
#define METHOD1D_H
#include "Mesh1D.h"

#include <unordered_map>
#include <vector>

class Method1D{
public:
    virtual ~Method1D() = default;
    virtual void setMesh(Mesh1D* mesh1d) = 0;
    virtual std::vector<double> getSolution( std::vector<std::vector<double>>& matrixA, std::vector<double>& matrixB) = 0;
protected:
    Mesh1D* mesh;
    std::unordered_map<std::string, double> paramtersOfTask;
    std::vector<double> solution;

};

#endif
