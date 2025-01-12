#ifndef LAXWENDROFFMETHOD1D_H
#define LAXWENDROFFMETHOD1D_H
#include "Method1D.h"

#include <unordered_map>
#include <vector>

class LaxWendroffMethod1D: public Method1D{
public:
    LaxWendroffMethod1D();
    virtual void getExplicitSolution() override;

private:
    std::function<double(double)> leftBC_;
    std::function<double(double)> rightBC_;
    std::function<double(double)> initialC_;

    std::vector<double> u_;
    std::vector<double> uNext_;
    std::vector<double> uPrev_;
    double сourantNumber_, t_;

};



#endif
