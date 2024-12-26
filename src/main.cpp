#include <iostream>
#include "RectangleMesh2D.h"
#include "LinearMesh1D.h"

int main() {
    LinearMesh1D proba1(5, 5);
    proba1.generateMesh();
    proba1.saveMesh("Mesh1d.txt");
    proba1.printMesh();


    return 0;
}
