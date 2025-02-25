#ifndef CRANKNICOLSONMETHOD1D_H
#define CRANKNICOLSONMETHOD1D_H

class CrankNicolsonMethod1D : public ImplicitMethod1D
{
  public:
    CrankNicolsonMethod1D() override;
    getSolution() override;
    setMatrix() override;
    setMatrixT() override;
};

#endif
