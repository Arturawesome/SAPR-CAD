#ifndef BODY2D_H
#define BODY2D_H

#include <vector>
#include <iostream>
#include "Mesh2D.h"

class Body2D{
protected:
    int num_of_elements = 0;
    std::string mesh_type_;
    std::string body_type_;
    double body_area_;
    std::shared_ptr<Mesh2D> mesh_;

public:
    virtual ~Body2D() = default;
    virtual getBodyType() = 0;
    virtual double getBodyArea() = 0;
    virtual std::vector<std::vector<int>> getBoundaryElements() = 0;
    virtual std::vector<std::vector<int>> getMesh() = 0;
    virtual void generateMesh() = 0;
};


#endif
