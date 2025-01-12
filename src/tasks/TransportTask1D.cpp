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
            lBC = std::stod(pair.second);
        } else if (pair.first == "rightBC") {
            rBC = std::stod(pair.second);
        } else if (pair.first == "initialCid") {
            initialCid = std::stod(pair.second);
        } else if (pair.first == "isTransferSpeedConst") {
            isTransferSpeedConst = pair.second == "false";
        }
    }
    std::cout<<"transferSpeed = "<<transferSpeed<<"\n";
    leftBC_ = [](double lbc) { return lbc; };
    leftBC_ = [](double rbc ) { return rbc; };
    if(initialCid == 0){
        initialC_ = [](double x) {
            return std::exp(-std::pow(x - 3.0, 2) / 0.25) + std::exp(-std::pow(x - 4.0, 2) / 0.25);
        };
    }

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

        meshT = std::make_unique<LinearMesh1D>(Nt, time, 't');
        meshT -> generateMesh();
        std::cout<<"time: \n";
        meshT -> printMesh();
        std::cout<<"\n\n";

    }
    double dx = mesh->GetNodesPosition('x', 1) - mesh->GetNodesPosition('x', 0);
    double dt = meshT->GetNodesPosition('t', 1) - meshT->GetNodesPosition('t', 0);
    std::cout<<"L = "<<L<<";  time = "<<time <<"\n\n";
    std::cout<<"Nx = "<<Nx<<";  Nt = "<<Nt <<"\n\n";
    std::cout<<"dx = "<<dx<<";  dt = "<<dt<<"\n\n";
    сourantNumber = transferSpeed * dt / dx;
    std::cout<<"сourantNumber = "<<сourantNumber<<"\n\n";

    if(сourantNumber > 1) {
        std::cout<<"!!!!!!!!!! WARNING !!!!!!!!!! WARNING !!!!!!!!!!\n!!!!!!!!!! WARNING !!!!!!!!!! WARNING !!!!!!!!!!\n\n";
        std::cout<<"Your Courant number more then 1";
    }


    if(paramtersOfTask["method"] == "LaxWendroffMethod1D"){
        std::cout<<"L = "<<L<<";  N = "<<N <<"\n\n";

        //method = std::make_unique<LaxWendroffMethod1D>();
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
    std::cout<<" initialCid = "<< initialCid <<"\n";
    std::cout<< "leftBC = "<< lBC<< ";  rightBC = "<< rBC<<"\n";
    std::cout<< "Nx = "<< Nx<<"; Nt = "<<Nt << ";  L = "<< L<<"\n";

}



void TransportTask1D::plotSolution(std::string nameFig){
    std::cout<<"void TransportTask1D::plotSolution()\n ";
}













