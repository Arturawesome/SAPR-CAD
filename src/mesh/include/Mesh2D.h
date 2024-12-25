#ifndef MESH2D_H
#define MESH2D_H
#include <vector>
#include <unordered_map>
class Mesh2D{
public:
    virtual ~Mesh2D() = default;
    virtual void generateMesh() = 0;
    virtual void saveMesh(std::string name_file) = 0;
    virtual int GetNumNodes(const char xyz) = 0;
protected:
    std::vector<std::vector<double>> nodes; //position of each node
    std::vector<std::vector<int>> elements; //
    std::unordered_map<char, int> numNodes;



};


#endif
