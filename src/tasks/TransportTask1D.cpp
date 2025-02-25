#include "TransportTask1D.h"

TransportTask1D::TransportTask1D(
    std::unordered_map<std::string, std::string> param) {
  this->paramtersOfTask_ = param;

  for (const auto &pair : paramtersOfTask_) {
    if (pair.first == "transferSpeed") {
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
    } else if (pair.first == "isStatic") {
      isStatic_ = pair.second == "true";
    }
  }
  double local_lbc = lBC_, local_rbc = rBC_;

  leftBC_ = [local_lbc](double _) { return local_lbc; };
  rightBC_ = [local_rbc](double x) { return local_rbc; };
  initialC_ = [](double x) {
    return std::exp(-std::pow(x - 3.0, 2) / 0.25) +
           std::exp(-std::pow(x - 4.0, 2) / 0.25);
  };
}

void TransportTask1D::solveTask() {
  if (paramtersOfTask_["meshType"] == "LinearMesh1D") {
    mesh_ = std::make_shared<LinearMesh1D>(Nx, L);
    mesh_->generateMesh();

    meshT_ = std::make_shared<LinearMesh1D>(Nt, time, 't');
    meshT_->generateMesh();
  }
  double dx = mesh_->GetNodesPosition('x', 1) - mesh_->GetNodesPosition('x', 0);
  double dt =
      meshT_->GetNodesPosition('t', 1) - meshT_->GetNodesPosition('t', 0);
  сourantNumber = transferSpeed_ * dt / dx;

  std::vector<double> xx = mesh_->GetNodesPosition('x');

  u_.resize(Nx, 0);
  uNext_.resize(Nx, 0);
  uPrev_.resize(Nx, 0);

  if (сourantNumber > 1) {
    std::cout << "!!!!!!!!!! WARNING !!!!!!!!!! WARNING !!!!!!!!!!\n!!!!!!!!!! "
                 "WARNING !!!!!!!!!! WARNING !!!!!!!!!!\n\n";
    std::cout << "Your Courant number more then 1";
  }

  if (paramtersOfTask_["method"] == "LaxWendroffMethod1D") {
    method_ = std::make_unique<LaxWendroffMethod1D>(
        leftBC_, rightBC_, initialC_, u_, uNext_, uPrev_, mesh_, meshT_,
        сourantNumber);
    solutionT_ = method_->getExplicitSolution();
    plotSolution("TransportTask1D" + paramtersOfTask_["meshType"] +
                 paramtersOfTask_["method"]);
  }
}

void TransportTask1D::getTaskDescription() {
  std::cout << "void TransportTask1D::getTaskDescription()\n";
  std::cout
      << "You are solving the transport equation with following paramters:\n";
  std::cout << "time = " << time << "\n";
  std::cout << "isTransferSpeedConst_ = " << isTransferSpeedConst_ << "\n";
  std::cout << "transferSpeed_ = " << transferSpeed_ << "\n";
  std::cout << " initialCid_ = " << initialCid_ << "\n";
  std::cout << "leftBC = " << lBC_ << ";  rightBC = " << rBC_ << "\n";
  std::cout << "Nx = " << Nx << "; Nt = " << Nt << ";  L = " << L << "\n";
}

void TransportTask1D::plotSolution(std::string nameFig) {
  std::vector<double> x = mesh_->GetNodesPosition('x');
  plt::plot(x, solutionT_[0], "o-");
  plt::plot(x, solutionT_[100], "o-");
  plt::show();
}

void TransportTask1D::saveTask() {
  std::string nameFile = "Transp1D" + paramtersOfTask_["method"];
  if (isStatic_) {
    std::ofstream fOutSolution(nameFile + ".txt");
    fOutSolution << "x, y\n";
    std::vector<double> x = mesh_->GetNodesPosition('x');
    for (int i = 0; i < Nx; ++i) {
      fOutSolution << x[i] << " " << solution[i] << "\n";
    }
    fOutSolution.close();
  } else {
    std::ofstream fOutSolution(nameFile + "_XY.txt");
    std::vector<double> x = mesh_->GetNodesPosition('x');
    fOutSolution << "x, ";
    for (int n = 0; n < Nt; ++n) {
      fOutSolution << "y" << n << " ";
    }
    fOutSolution << "\n";
    for (int i = 0; i < Nx; ++i) {
      fOutSolution << x[i] << " ";
      for (int n = 0; n < Nt; ++n) {
        fOutSolution << solutionT_[n][i] << " ";
      }
      fOutSolution << "\n";
    }
    fOutSolution.close();

    std::ofstream fOutTime(nameFile + "T.txt");
    std::vector<double> time = meshT_->GetNodesPosition('t');
    for (int n = 0; n < Nt; ++n) {
      fOutTime << time[n] << "\n";
    }
    fOutTime.close();
  }
}
