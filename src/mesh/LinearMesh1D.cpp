#include "LinearMesh1D.h"

LinearMesh1D::LinearMesh1D(int numNodesX, double size_x ){
    std::cout<<"LinearMesh1D::LinearMesh1D(int numNodesX, double size_x )\n ";
    numNodes['x'] = numNodesX;
    size['x'] = size_x;
}

LinearMesh1D::LinearMesh1D(){
    //std::cout<<"LinearMesh1D() numNodesX = 10; numNodesY = 10; size_x = 1; size_y = 1\n ";
    numNodes['x'] = 10;
    size['x'] = 1;
}


int LinearMesh1D:: GetNumNodes(const char xyz){
    //std::cout<<"GetNumNodes\n";
    return numNodes[xyz];
}

void LinearMesh1D::generateMesh(){
    std::cout<<"void LinearMesh1D::generateMesh()\n";
    dx =  size['x'] / (numNodes['x'] -1);
    for(int i = 0; i < numNodes['x']; ++i){
        nodesPosition.push_back(i * dx);
        if( i == 0 || i ==  numNodes['x']-1){
            boundaryNodesId.push_back(i );
        }
    }

    for(int i = 0; i < numNodes['x']; ++i){
        if (i < numNodes['x']-1 ){
                elementsId.push_back({i, i+1});
                if(i == 0 || i == numNodes['x']-2 ){
                    boundaryElements.push_back({i, i+1});
                }
            } else {
                elementsId.push_back({-1, -1});
            }
        }
}



void LinearMesh1D::printMesh(){
    std::cout << "Nodes:\n";
    for (size_t i = 0; i < nodesPosition.size(); ++i) {
        std::cout << i << ": (" << nodesPosition[i] << ", ";
    }

    std::cout << "\n Elements:\n";
    for (const auto& elem : elementsId) {
        for (int id : elem) {
            std::cout << id << " ";
        }
        std::cout << "\n";
    }
}


void LinearMesh1D::saveMesh(std::string name_file) {
    std::ofstream outFile(name_file);
    if (!outFile.is_open()) {
        std::cerr << "Error: File is not open!" << std::endl;
        return;
    }
    for(int i = 0; i < numNodes['x']; ++i){
        outFile <<std::setw(5) << nodesPosition[i]<<";      ";
    }

    outFile << std::endl;
    for(int i = 0; i < numNodes['x']; ++i) {
        outFile <<std::setw(3) << elementsId[i][0]<< std::setw(3) << elementsId[i][1]<< ";      ";
    }
    outFile << std::endl;
    outFile << std::endl;

    outFile.close();

}




