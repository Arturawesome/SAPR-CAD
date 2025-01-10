#include "TransportTask1D.h"

TransportTask1D::TransportTask1D(std::unordered_map<std::string, std::string> param){
    this->paramtersOfTask = param;

    for(const auto & pair: paramtersOfTask){
        if(pair.first == "transferSpeed"){
            transferSpeed = std::stod(pair.second);
        } else if (pair.first == "Nx") {
            Nx = std::stod(pair.second);
        } else if (pair.first == "Nt") {
            Nt = std::stod(pair.second);
        } else if (pair.first == "L") {
            L = std::stod(pair.second);
        } else if (pair.first == "time") {
            time = std::stod(pair.second);
        } else if (pair.first == "leftBC") {
            leftBC = std::stod(pair.second);
        } else if (pair.first == "rightBC") {
            rightBC = std::stod(pair.second);
        } else if (pair.first == "initialC") {
            initialC = std::stod(pair.second);
        } else if (pair.first == "isTransferSpeedConst") {
            isTransferSpeedConst = pair.second == "false";
        }
    }
    std::cout<<"transferSpeed = "<<transferSpeed<<"\n";
}


void TransportTask1D::solveTask(){
    std::cout<<"void TransportTask1D::solveTask()\n ";

    if(paramtersOfTask["meshType"] == "LinearMesh1D"){
        std::cout<<"L = "<<L<<";  N = "<<N <<"\n\n";
        mesh = std::make_unique<LinearMesh1D>(Nx, L);
        mesh -> generateMesh();
        std::cout<<"L: \n";
        mesh -> printMesh();
        std::cout<<"\n\n";

        meshT = std::make_unique<LinearMesh1D>(Nt, time);
        meshT -> generateMesh();
        std::cout<<"time: \n";
        meshT -> printMesh();
        std::cout<<"\n\n";

    }
    сourantNumber = mesh->GetNodesPosition('x', 0) - mesh->GetNodesPosition('x', 1);


    if(paramtersOfTask["method"] == "FiniteDifferenceMethod1D"){
        std::cout<<"L = "<<L<<";  N = "<<N <<"\n\n";
        // setMatrixAndConditions();
        // method = std::make_unique<FiniteDifferenceMethod1D>();
        //
        // solution = method -> getSolution(matrixA, matrixB);
        // plotSolution("HeatTask1D_" + paramtersOfTask["method"] + "_" + paramtersOfTask["meshType"] );
    }
}

void TransportTask1D::getTaskDescription(){

    std::cout<<"void TransportTask1D::getTaskDescription()\n";
    std::cout<<"You are solving the transport equation with following paramters:\n";

    std::cout<< "time = "<< time<<"\n";
    std::cout<< "isTransferSpeedConst = " << isTransferSpeedConst<<"\n";


    std::cout<< "transferSpeed = "<<transferSpeed<<"\n";
    std::cout<<" initialC = "<< initialC <<"\n";
    std::cout<< "leftBC = "<< leftBC<< ";  rightBC = "<< rightBC<<"\n";
    std::cout<< "Nx = "<< Nx<<"; Nt = "<<Nt << ";  L = "<< L<<"\n";

}



void TransportTask1D::plotSolution(std::string nameFig){
    std::cout<<"void TransportTask1D::plotSolution()\n ";
}













