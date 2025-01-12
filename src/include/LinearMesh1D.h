#ifndef LINEARMESH1D_H
#define LINEARMESH1D_H
#include <fstream>
#include <iomanip>

#include "Mesh1D.h"
#include <iostream>
#include <unordered_map>

class LinearMesh1D: public Mesh1D {
public:

    LinearMesh1D(int numNodesX, double size_x, const char xyzt = 'x');
    LinearMesh1D();

    virtual void generateMesh() override;
    virtual void printMesh() override;
    virtual void saveMesh(std::string name_file) override;
    virtual int GetNumNodes(const char xyzt) override;
    virtual double GetNodesPosition(const char xyzt, int i) override;
    virtual std::vector<double> GetNodesPosition(const char xyzt) override;


private:
    std::unordered_map<char, double> size;
    double dx;



};

#endif
