#include "HeatTask1D.h"

HeatTask1D::HeatTask1D(std::unordered_map<std::string, std::string> param){
    std::cout<<"HeatTask1D::HeatTask1D\n";
    this->paramtersOfTask = param;
}

void HeatTask1D::getTaskDescription(){
    std::cout<<"void HeatTask1D::getTaskDescription()\n";
    std::cout<<"You solve the heat equation with following paramters:\n you set: \n";

    for(const auto& pair: paramtersOfTask){
        std::cout<<pair.first<<" = "<< std::setw(8)<<pair.second<<"\n";
    }

}

void HeatTask1D::solveTask(){
    std::cout<<"void HeatTask1D::solveTask()\n";
}
