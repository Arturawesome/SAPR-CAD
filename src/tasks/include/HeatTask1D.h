#ifndef HEATTASK1D_H
#define HEATTASK1D_H

#include "FiniteDifferenceMethod1D.h"
#include "LinearMesh1D.h"
#include "Task1D.h"

class HeatTask1D : public Task1D {

public:
  HeatTask1D(std::unordered_map<std::string, std::string> param);
  virtual void solveTask() override;
  virtual void getTaskDescription() override;
  virtual void plotSolution(std::string nameFig) override;
  void setMatrixAndConditions();

private:
  bool isInternalHeatSource = false;
  double Xsource = -1, Ysource = -1, Qsource;

  double Tleft = -1, Tright = -1;
  double alpha = -1;
};

#endif
