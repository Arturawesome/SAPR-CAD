#include "LaxWendroffMethod1D.h"

LaxWendroffMethod1D::LaxWendroffMethod1D( std::function<double(double)> leftBC,
                                          std::function<double(double)> rightBC,
                                          std::function<double(double)> initialC,
                                          std::vector<double>& u,
                                          std::vector<double>& uNext,
                                          std::vector<double>& uPrev,
                                          std::shared_ptr<Mesh1D> meshx,
                                          std::shared_ptr<Mesh1D> meshT,
                                          double сourantNumber
                                          ):
leftBC_(leftBC), rightBC_(rightBC),initialC_(initialC), u_(u), uNext_(uNext), uPrev_(uPrev), meshx_(std::move(meshx)), meshT_(std::move(meshT)), сourantNumber_(сourantNumber)
{
    std::cout<<"LaxWendroffMethod1D::LaxWendroffMethod1D\n";
    sizeMeshx_ = meshx_->GetNumNodes('x');
    sizeMesht_ = meshT_->GetNumNodes('t');
    std::cout<<"sizeMeshx_ = "<<sizeMeshx_<<";  sizeMesht_ = "<<sizeMesht_<<"\n";

}
void LaxWendroffMethod1D::setInitialConditions(){
    u_[0] = leftBC_(0);
    u_[sizeMeshx_-1] = rightBC_(0);
    for(int i = 1; i < sizeMeshx_ - 1; ++i){
        double xi = meshx_ -> GetNodesPosition('x', i);
        u_[i] = initialC_(xi);
    }
    solutionT_.push_back(u_);
}

void LaxWendroffMethod1D::numericalScheme(int ts){
    // set initial conditions

    uNext_[0] = leftBC_(0);
    uNext_[sizeMeshx_-1] = rightBC_(0);
    for(int i = 1; i < sizeMeshx_ - 1; ++i){
        uNext_[i] = u_[i] - сourantNumber_ * (u_[i+1] - u_[i-1]) / 2 + сourantNumber_ * сourantNumber_ * (u_[i+1] - 2*u_[i] + u_[i-1]) / 2;
    }
    solutionT_.push_back(uNext_);


}
std::vector<std::vector<double>> LaxWendroffMethod1D::getExplicitSolution()
{
    std::cout<<"LaxWendroffMethod1D::getSolution()\n\n";
    std::cout<<"sizeMeshx_ = "<<sizeMeshx_<<";  sizeMesht_ = "<<sizeMesht_<<"\n\n";

    setInitialConditions();
    for(int ts = 1; ts < sizeMesht_; ++ts)
    {
        std::cout<<ts<<" ";
        numericalScheme(ts);
        std::swap(uPrev_, u_);
        std::swap(u_, uNext_);
        uNext_.assign(sizeMeshx_, 0);
        //std::fill(uNext_.begin(), uNext_.end(), 0);
    }
    std::cout<<"solutionT_\n";
    return solutionT_;
}

















