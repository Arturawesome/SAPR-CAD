#include "LaxWendroffMethod1D.h"

LaxWendroffMethod1D::LaxWendroffMethod1D( std::function<double(double)> leftBC,
                                          std::function<double(double)> rightBC,                                  std::vector<double>& u,
                                          std::vector<double>& uNext,
                                          std::vector<double>& uPrev,
                                          std::unique_ptr<Mesh1D>&& meshx,
                                          std::unique_ptr<Mesh1D>&& meshT,
                                          double сourantNumber
                                          ):
leftBC_(leftBC), rightBC_(rightBC), u_(u), uNext_(uNext), uPrev_(uPrev), meshx_(std::move(meshx)), meshT_(std::move(meshT)), сourantNumber_(сourantNumber)
{}


void LaxWendroffMethod1D::getExplicitSolution()
{
    std::cout<<"LaxWendroffMethod1D::getSolution()\n";

}
