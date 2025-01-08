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
        } else if (pair.first == "Qsource") {
            Qsource = std::stod(pair.second);
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
        mesh ->printMesh();
    }


    if(paramtersOfTask["method"] == "FiniteDifferenceMethod1D"){
        setMatrixAndConditions();
        std::cout<<"\n setMatrixAndConditions; matrix conditions were created \n\n";
        method = std::make_unique<FiniteDifferenceMethod1D>();
        solution = method -> getSolution(matrixA, matrixB);
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    for(auto el: solution){
        std::cout<<el<<";  ";
    }
    std::cout<<std::endl;

}

void HeatTask1D::setMatrixAndConditions(){
    std::cout<<"void HeatTask1D::setMatrixAndConditions()\n";
    //Шаг по пространству
    double dx;
    double coeff;
    matrixB.resize(N, 0.0);
    matrixA.resize(N, std::vector<double>(N, 0.0));

    for(int i = 1 ; i < N-1; ++i){
        dx = mesh->GetNodesPosition('x', i) - mesh->GetNodesPosition('x', i-1);
        coeff = alpha * dx* dx;
        std::cout<<"mesh->GetNodesPosition('x', i) = "<<mesh->GetNodesPosition('x', i)<<"\n";
        std::cout<<"mesh->GetNodesPosition('x', i-1) = "<<mesh->GetNodesPosition('x', i-1)<<"\n";

        std::vector<double> v(N, 0);


        matrixA[i][i-1] = 1.0;
        matrixA[i][i] = -2.0 + coeff;
        matrixA[i][i+1] = 1.0;


        if(isInternalHeatSource) {
            if(std::abs(i * dx - Xsource) < dx / 2) {
                matrixB[i] = coeff * Tright - Qsource * dx * dx;
            } else {
                matrixB[i] = -coeff * Tright;
            }
        } else {
            matrixB[i] = -coeff * Tright;
        }
    }

    matrixA[0][0] = 1.0;
    matrixB[0] = Tleft;
    matrixA[N - 1][N - 1] = -1.0 / dx;
    matrixA[N - 1][N - 2] = 1.0 / dx;

    for(int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            std::cout<<matrixA[i][j]<<"  ";
        }
        std::cout<<";  "<<matrixB[i]<<"  \n";
    }
}



















