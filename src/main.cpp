#include <iostream>
#include "RectangleMesh2D.h"


int main() {
    std::cout << "Hello from main: Starting program..." << std::endl;
    RectangleMesh2D proba(4, 6, 5, 5);
    proba.generateMesh();
    proba.saveMesh("Mesh.txt");
    return 0;
}
