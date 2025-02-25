#ifndef TRANSPORTTASK1D_H
#define TRANSPORTTASK1D_H

#include "LaxWendroffMethod1D.h"
#include "LinearMesh1D.h"
#include "Task1D.h"

class TransportTask1D : public Task1D
{
  public:
    TransportTask1D(std::unordered_map<std::string, std::string> param);
    virtual void solveTask() override;
    virtual void getTaskDescription() override;
    virtual void plotSolution(std::string nameFig) override;
    virtual void saveTask() override;

  private:
    std::function<double(double)> leftBC_;
    std::function<double(double)> rightBC_;
    std::function<double(double)> initialC_;

    std::vector<double> u_;
    std::vector<double> uNext_;
    std::vector<double> uPrev_;

    double transferSpeed_;
    double lBC_;
    double rBC_;

    int initialCid_;
    bool isTransferSpeedConst_;
};

#endif
