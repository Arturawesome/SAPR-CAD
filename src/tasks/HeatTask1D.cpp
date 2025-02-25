#include "HeatTask1D.h"

HeatTask1D::HeatTask1D(std::unordered_map<std::string, std::string> param) {
  this->paramtersOfTask_ = param;

  for (const auto &pair : param) {
    if (pair.first == "isStatic") {
      isStatic_ = pair.second == "true";
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

void HeatTask1D::getTaskDescription() {
  std::cout << "void HeatTask1D::getTaskDescription()\n";
  std::cout
      << "You solve the heat equation with following paramters:\n you set: \n";
  std::cout << "useCustomMesh = " << useCustomMesh << "\n";

  std::cout << "time = " << time << ";  dt = " << dt << "\n";
  std::cout << "isStatic_ = " << isStatic_ << "\n";

  std::cout << "isInternalHeatSource = " << isInternalHeatSource << "\n";
  std::cout << "Xsource = " << Xsource << ";  Ysource = " << Ysource << "\n";

  std::cout << "Tleft = " << Tleft << ";  Tright = " << Tright << "\n";
  std::cout << "alpha = " << alpha << "\n";
  std::cout << "N = " << N << ";  L = " << L << "\n";
}

void HeatTask1D::solveTask() {
  std::cout << "void HeatTask1D::solveTask()\n";
  if (paramtersOfTask_["meshType"] == "LinearMesh1D") {
    std::cout << "L = " << L << ";  N = " << N << "\n\n";
    mesh_ = std::make_shared<LinearMesh1D>(N, L);
    mesh_->generateMesh();
    std::cout << "LinearMesh1D was created\n";
    mesh_->printMesh();
  }

  if (paramtersOfTask_["method"] == "FiniteDifferenceMethod1D") {
    setMatrixAndConditions();
    method_ = std::make_shared<FiniteDifferenceMethod1D>();

    solution = method_->getSolution(matrixA, matrixB);
    plotSolution("HeatTask1D_" + paramtersOfTask_["method"] + "_" +
                 paramtersOfTask_["meshType"]);
  }
}

void HeatTask1D::setMatrixAndConditions() {
  // std::cout<<"void HeatTask1D::setMatrixAndConditions()\n\n";
  double dx;
  double coeff;
  matrixB.resize(N, 0.0);
  matrixA.resize(N, std::vector<double>(N, 0.0));

  for (int i = 1; i < N - 1; ++i) {
    dx = mesh_->GetNodesPosition('x', i) - mesh_->GetNodesPosition('x', i - 1);
    coeff = alpha * dx * dx;

    std::vector<double> v(N, 0);

    matrixA[i][i - 1] = 1.0;
    matrixA[i][i] = -(2.0 + coeff);
    matrixA[i][i + 1] = 1.0;

    if (isInternalHeatSource) {
      if (std::abs(i * dx - Xsource) < dx / 2) {
        matrixB[i] = -coeff * Tright - Qsource * dx * dx;
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

  // for(int i = 0; i < N; ++i){
  //     for (int j = 0; j < N; ++j){
  //         std::cout<<matrixA[i][j]<<"  ";
  //     }
  //     std::cout<<";  "<<matrixB[i]<<"  \n";
  // }
}

void HeatTask1D::plotSolution(std::string nameFig) {
  // std::cout<<"void HeatTask1D::plotSolution()\n";
  std::vector<double> x = mesh_->GetNodesPosition('x');

  plt::plot(x, solution, "o-");
  plt::show();
  // plt::clf();
}
