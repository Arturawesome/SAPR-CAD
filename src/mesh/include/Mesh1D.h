#ifndef MESH1D_H
#define MESH1D_H
#include <vector>
#include <unordered_map>
#include <string>
class Mesh1D{
public:
    virtual ~Mesh1D() = default;
    virtual void generateMesh() = 0;
    virtual void saveMesh(std::string name_file) = 0;
    virtual void printMesh() = 0;
    virtual int GetNumNodes(const char xyz) = 0;
    virtual double GetNodesPosition(const char xyz, int i) = 0;

protected:
    //position of each node
    std::vector<double> nodesPosition;
    std::unordered_map<char, std::vector<double>> nodesPosition2;

    // id of nodes whic create the elements (rectangle element, triangle one or another one)
    std::vector<std::vector<int>> elementsId;

    // number of nodes in X and Y
    std::unordered_map<char, int> numNodes;

    // id of nodes which located on the boundary
    std::vector<int> boundaryNodesId;
    std::unordered_map<char, std::vector<double>> boundaryNodesId2;

    // id of nodes which create the element and it element located on the boundary
    std::vector<std::vector<int>> boundaryElements;



};


#endif
