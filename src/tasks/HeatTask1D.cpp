#include "HeatTask1D.h"

HeatTask1D::HeatTask1D(std::unordered_map<std::string, std::string> param){
    this->paramtersOfTask = param;

    for(const auto &pair: param){
        if(pair.first == "isStatic") {
            isStatic = pair.second == "true";
        } else if (pair.first == "isInternalHeatSource") {
            isInternalHeatSource = pair.second == "true";
        } else if (pair.first == "time") {
            time = std::stod(pair.second);
        } else if (pair.first == "dt") {
            dt = std::stod(pair.second);
        } else if (pair.first == "Xsource") {
            Xsource = std::stod(pair.second);
        } else if (pair.first == "Ysource") {
            Ysource = std::stod(pair.second);
        } else if (pair.first == "Tleft") {
            Tleft = std::stod(pair.second);
        } else if (pair.first == "Tright") {
            Tright = std::stod(pair.second);
        } else if (pair.first == "alpha") {
            alpha = std::stod(pair.second);
        } else if (pair.first == "N") {
            N = std::stod(pair.second);
        } else if (pair.first == "L") {
            L = std::stod(pair.second);
        } else if (pair.first == "useCustomMesh") {
            useCustomMesh = pair.second == "false";
        } else if (pair.first == "useCustomMethod") {
            useCustomMethod = pair.second == "false";
        }
    }

}



void HeatTask1D::getTaskDescription(){
    std::cout<<"void HeatTask1D::getTaskDescription()\n";
    std::cout<<"You solve the heat equation with following paramters:\n you set: \n";
    std::cout<< "useCustomMesh = "<<useCustomMesh<<"\n";

    std::cout<< "time = "<< time<<";  dt = "<<dt<<"\n";
    std::cout<< "isStatic = " << isStatic<<"\n";

    std::cout<< "isInternalHeatSource = " << isInternalHeatSource<<"\n";
    std::cout<< "Xsource = "<< Xsource << ";  Ysource = "<< Ysource<<"\n";

    std::cout<< "Tleft = "<< Tleft<< ";  Tright = "<< Tright<<"\n";
    std::cout<< "alpha = "<< alpha<<"\n";
    std::cout<< "N = "<< N << ";  L = "<< L<<"\n";

}

void HeatTask1D::solveTask(){
    std::cout<<"void HeatTask1D::solveTask()\n";
    if(paramtersOfTask["meshType"] == "LinearMesh1D"){
        mesh = std::make_unique<LinearMesh1D>(L, N);
        mesh -> generateMesh();
        std::cout<<"LinearMesh1D was created\n";
    }



    if(paramtersOfTask["method"] == "FiniteDifferenceMethod1D"){
        method = std::make_unique<FiniteDifferenceMethod1D>();
        method -> getSolution();
    }


}




















