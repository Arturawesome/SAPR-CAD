#ifndef MESH2D_H
#define MESH2D_H
#include <vector>
#include <unordered_map>
class Mesh2D{
public:
    virtual ~Mesh2D() = default;
    virtual void generateMesh() = 0;
    virtual void saveMesh(std::string name_file) = 0;
    virtual void printMesh() = 0;
    virtual int GetNumNodes(const char xyz) = 0;

protected:
    //position of each node
    std::vector<std::vector<double>> nodesPosition;

    // id of nodes whic create the elements (rectangle element, triangle one or another one)
    std::vector<std::vector<int>> elementsId;

    // number of nodes in X and Y
    std::unordered_map<char, int> numNodes;

    // id of nodes which located on the boundary
    std::vector<int> boundaryNodesId;

    // id of nodes which create the element and it element located on the boundary
    std::vector<std::vector<int>> boundaryElements;



};


#endif
