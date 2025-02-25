#ifndef RECTANGLEMESH2D_H
#define RECTANGLEMESH2D_H
#include <fstream>
#include <iomanip>

#include "Mesh2D.h"
#include <iostream>
#include <unordered_map>

class RectangleMesh2D : public Mesh2D
{
  public:
    RectangleMesh2D(int numNodesX, int numNodesY, double size_x, double size_y);
    RectangleMesh2D();

    virtual void generateMesh() override;
    virtual void printMesh() override;
    virtual void saveMesh(std::string name_file) override;
    virtual int GetNumNodes(const char xyz) override;

  private:
    std::unordered_map<char, double> size;
    double dx;
    double dy;
};

#endif
