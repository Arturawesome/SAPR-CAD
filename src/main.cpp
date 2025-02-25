#include <iostream>

#include "FiniteDifferenceMethod1D.h"
#include "HeatTask1D.h"
#include "LinearMesh1D.h"

#include "TransportTask1D.h"

int main() {

  /*
      std::unordered_map<std::string, std::string> parameterOfTask = {
          //{"isStatic", "True"},
          //{"time", "0"},
          //{"dt", "0"},

          {"isInternalHeatSource", "False"},
          {"Xsource", "0"},
          {"Ysource", "0"},

          {"method", "FiniteDifferenceMethod1D"},

          {"meshType", "LinearMesh1D"},
          {"N", "15"},
          {"L", "1"},

          {"alpha", "25"},
          {"Tleft", "100"},
          {"Tright", "20"}
      };
      HeatTask1D task(parameterOfTask);
      task.getTaskDescription();
      task.solveTask();
      std::cout<<"\n\n\n\n\n\n";*/

  std::unordered_map<std::string, std::string> parameterOfTask2 = {
      {"method", "LaxWendroffMethod1D"},
      {"meshType", "LinearMesh1D"},
      {"isStatic", "false"},

      {"L", "10"},
      {"Nx", "500"}, // N=L/dx
      {"time", "3.5"},
      {"Nt", "350"}, // M=T/dt

      {"isTransferSpeedConst", "true"},
      {"transferSpeed", "1"},
      {"leftBC", "0"},
      {"rightBC", "0"},
      {"initialCid",
       "0"}, // not parser -> choose the variance 1 - sin; 2 - sum of two gauss
  };
  TransportTask1D task2(parameterOfTask2);
  task2.getTaskDescription();
  task2.solveTask();
  task2.saveTask();

  return 0;
}
