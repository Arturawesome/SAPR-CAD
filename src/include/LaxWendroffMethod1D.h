#ifndef LAXWENDROFFMETHOD1D_H
#define LAXWENDROFFMETHOD1D_H
#include "Method1D.h"

#include <unordered_map>
#include <vector>

class LaxWendroffMethod1D: public Method1D{
public:
    LaxWendroffMethod1D(std::function<double(double)> leftBC,
                        std::function<double(double)> rightBC,
                        std::function<double(double)> initialC,
                        std::vector<double>& u,
                        std::vector<double>& uNext,
                        std::vector<double>& uPrev,
                        std::unique_ptr<Mesh1D>&& meshx,
                        std::unique_ptr<Mesh1D>&& meshT,
                        double сourantNumber
                        );
    virtual std::vector<std::vector<double>> getExplicitSolution() override;
    virtual void numericalScheme(int ts) override;
private:
    std::function<double(double)> leftBC_;
    std::function<double(double)> rightBC_;
    std::function<double(double)> initialC_;

    std::vector<double> u_;
    std::vector<double> uNext_;
    std::vector<double> uPrev_;

    std::unique_ptr<Mesh1D> meshx_;
    std::unique_ptr<Mesh1D> meshT_;

    double сourantNumber_, t_;

};



#endif
