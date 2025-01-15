#include "TransportTask1D.h"

TransportTask1D::TransportTask1D(std::unordered_map<std::string, std::string> param){
    this->paramtersOfTask_ = param;

    for(const auto & pair: paramtersOfTask_){
        if(pair.first == "transferSpeed"){
            transferSpeed_ = std::stod(pair.second);
        } else if (pair.first == "Nx") {
            Nx = std::stod(pair.second);
        } else if (pair.first == "Nt") {
            Nt = std::stod(pair.second);
        } else if (pair.first == "L") {
            L = std::stod(pair.second);
        } else if (pair.first == "time") {
            time = std::stod(pair.second);
        } else if (pair.first == "leftBC") {
            lBC_ = std::stod(pair.second);
        } else if (pair.first == "rightBC") {
            rBC_ = std::stod(pair.second);
        } else if (pair.first == "initialCid_") {
            initialCid_ = std::stod(pair.second);
        } else if (pair.first == "isTransferSpeedConst") {
            isTransferSpeedConst_ = pair.second == "false";
        }
    }

    std::cout<<"transferSpeed_ = "<<transferSpeed_<<"\n";

    double local_lbc = lBC_, local_rbc = rBC_;
    leftBC_ = [local_lbc](double _) { return local_lbc; };
    rightBC_ = [local_rbc](double _) { return local_rbc; };
    if(initialCid_ == 0){
        initialC_ = [](double x) {
            return std::exp(-std::pow(x - 3.0, 2) / 0.25) + std::exp(-std::pow(x - 4.0, 2) / 0.25);
        };
    }

}


void TransportTask1D::solveTask(){
    std::cout<<"void TransportTask1D::solveTask()\n ";

    if(paramtersOfTask_["meshType"] == "LinearMesh1D"){
        std::cout<<"L = "<<L<<";  N = "<<N <<"\n\n";
        mesh_ = std::make_unique<LinearMesh1D>(Nx, L);
        mesh_ -> generateMesh();
        std::cout<<"L: \n";
        mesh_ -> printMesh();
        std::cout<<"\n\n";

        meshT_ = std::make_unique<LinearMesh1D>(Nt, time, 't');
        meshT_-> generateMesh();
        std::cout<<"time: \n";
        meshT_ -> printMesh();
        std::cout<<"\n\n";

    }
    double dx = mesh_->GetNodesPosition('x', 1) - mesh_->GetNodesPosition('x', 0);
    double dt = meshT_->GetNodesPosition('t', 1) - meshT_->GetNodesPosition('t', 0);
    std::cout<<"L = "<<L<<";  time = "<<time <<"\n\n";
    std::cout<<"Nx = "<<Nx<<";  Nt = "<<Nt <<"\n\n";
    std::cout<<"dx = "<<dx<<";  dt = "<<dt<<"\n\n";
    сourantNumber = transferSpeed_ * dt / dx;
    std::cout<<"сourantNumber = "<<сourantNumber<<"\n\n";

    if(сourantNumber > 1) {
        std::cout<<"!!!!!!!!!! WARNING !!!!!!!!!! WARNING !!!!!!!!!!\n!!!!!!!!!! WARNING !!!!!!!!!! WARNING !!!!!!!!!!\n\n";
        std::cout<<"Your Courant number more then 1";
    }


    if(paramtersOfTask_["method"] == "LaxWendroffMethod1D"){
        std::cout<<"L = "<<L<<";  N = "<<N <<"\n\n";

        method_ = std::make_unique<LaxWendroffMethod1D>(leftBC_,
                                                       rightBC_,
                                                       u_,
                                                       uNext_,
                                                       uPrev_,
                                                       std::move(mesh_),
                                                       std::move(meshT_),
                                                       сourantNumber);
        //
        // solution = method -> getSolution(matrixA, matrixB);
        // plotSolution("HeatTask1D_" + paramtersOfTask_["method"] + "_" + paramtersOfTask_["meshType"] );
    }
}

void TransportTask1D::getTaskDescription(){

    std::cout<<"void TransportTask1D::getTaskDescription()\n";
    std::cout<<"You are solving the transport equation with following paramters:\n";

    std::cout<< "time = "<< time<<"\n";
    std::cout<< "isTransferSpeedConst_ = " << isTransferSpeedConst_<<"\n";


    std::cout<< "transferSpeed_ = "<<transferSpeed_<<"\n";
    std::cout<<" initialCid_ = "<< initialCid_ <<"\n";
    std::cout<< "leftBC = "<< lBC_<< ";  rightBC = "<< rBC_<<"\n";
    std::cout<< "Nx = "<< Nx<<"; Nt = "<<Nt << ";  L = "<< L<<"\n";

}



void TransportTask1D::plotSolution(std::string nameFig){
    std::cout<<"void TransportTask1D::plotSolution()\n ";
}













