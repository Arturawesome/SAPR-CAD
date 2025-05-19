#ifndef RECTANGLE2D_H
#define RECTANGLE2D_H
#include "Body2D.h"


class Reactangle2D: public Body2D{

public:
    Rectangle2D(int num_elements, int x_max, int y_max, std::string mesh_type);
    getBodyType() override;
     double getBodyArea() override;
     std::vector<std::vector<int>> getBoundaryElements() override;
     std::vector<std::vector<int>> getMesh() override;
     void generateMesh() override;
};


#endif
