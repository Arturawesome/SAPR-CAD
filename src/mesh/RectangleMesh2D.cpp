#include "RectangleMesh2D.h"

RectangleMesh2D::RectangleMesh2D(int numNodesX, int numNodesY, double size_x, double size_y){
    std::cout<<"In RectangleMesh2D(int numNodesX, int numNodesY, double size_x, double size_y){\n ";
    numNodes['x'] = numNodesX;
    numNodes['y'] = numNodesY;
    size['x'] = size_x;
    size['y'] = size_y;
}

RectangleMesh2D::RectangleMesh2D(){
    std::cout<<"RectangleMesh2D() numNodesX = 10; numNodesY = 10; size_x = 1; size_y = 1\n ";
    numNodes['x'] = 10;
    numNodes['y'] = 10;
    size['x'] = 1;
    size['y'] = 1;
}


int RectangleMesh2D:: GetNumNodes(const char xyz){
    std::cout<<"GetNumNodes\n";
    return numNodes[xyz];
}

void RectangleMesh2D::generateMesh(){
    dx =  size['x'] / (numNodes['x'] -1);
    dy =  size['y'] / (numNodes['y'] - 1);

    for(int i = 0; i < numNodes['x']; ++i){
        for(int j = 0; j < numNodes['y']; ++j) {
            nodes.push_back({i * dx, j * dy});
        }
    }
    for(int i = 0; i < numNodes['x']; ++i){
        for(int j = 0; j < numNodes['y']; ++j) {
            int n0 = i *  numNodes['y'] + j;
            int n1 = n0 +1;
            int n2 = n0 +  numNodes['y'];
            int n3 = n2 + 1;
            elements.push_back({n0, n1, n2, n3});
        }
    }
}
void RectangleMesh2D::saveMesh(std::string name_file) {
    std::ofstream outFile(name_file);
    if (!outFile.is_open()) {
        std::cerr << "Error: File is not open!" << std::endl;
        return;
    }
    for(int i = 0; i < numNodes['x']; ++i){
        for(int j = 0; j < numNodes['y']; ++j) {
            int id = numNodes['y'] * i + j;
            //outFile << id<<"/"<< nodes[id].size()<<";  ";
            outFile <<std::setw(5) << nodes[id][0]<< std::setw(5) << nodes[id][1]<<std::setw(5)<<id<<";      ";
        }
        outFile << std::endl;
        for(int j = 0; j < numNodes['y']; ++j) {
            int id = numNodes['y'] * i + j;
            outFile <<std::setw(3) << elements[id][0]<< std::setw(3) << elements[id][1]<< std::setw(3) << elements[id][2]<< std::setw(3) << elements[id][3]<<";      ";
        }
        outFile << std::endl;
        outFile << std::endl;
    }
    outFile.close();

}




