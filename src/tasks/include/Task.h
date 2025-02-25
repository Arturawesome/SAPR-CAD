#ifndef TASK1D_H
#define TASK1D_H

#include <unordered_map>
class Task : public Method1D, public Mesh1D {
public:
  virtual ~Task() default;
  virtual SetParameters(
      std::string typeTask, int dim,
      std::unordered_map<std::string, double> paramtersOfTask) = 0;
  virtual solveTask(Method1D method1d, Mesh1D mesh1d) = 0;

private:
  std::unordered_map<std::string, double> paramtersOfTask;
  int dimension;
};

#endif
