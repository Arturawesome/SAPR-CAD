#include "LaxWendroffMethod1D.h"

LaxWendroffMethod1D::LaxWendroffMethod1D( std::function<double(double)> leftBC,
                                          std::function<double(double)> rightBC,                                  std::vector<double>& u,
                                          std::vector<double>& uNext,
                                          std::vector<double>& uPrev,
                                          double сourantNumber,
                                          double t)
leftBC_(leftBC), rightBC_(rightBC), u_(u), uNext_(uNext), uPrev_(uPrev), сourantNumber_(C), t_(t)
{}


void LaxWendroffMethod1D::getExplicitSolution()
{
    std::cout<<"LaxWendroffMethod1D::getSolution()\n";

}
