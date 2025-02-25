#include "FiniteDifferenceMethod1D.h"

FiniteDifferenceMethod1D::FiniteDifferenceMethod1D()
{
    std::cout << "FiniteDifferenceMethod1D::FiniteDifferenceMethod1D\n";
}

std::vector<double>
FiniteDifferenceMethod1D::getSolution(std::vector<std::vector<double>>& matrixA,
                                      std::vector<double>& matrixB)
{
    // std::cout<<"FiniteDifferenceMethod1D::getSolution()\n";
    int N = matrixB.size();
    std::vector<double> T(N, 0);
    std::vector<double> c;
    std::vector<double> d;
    c.resize(N, 0);
    d.resize(N, 0);

    // forward pass
    c[0] = matrixA[0][1] / matrixA[0][0];
    d[0] = matrixB[0] / matrixA[0][0];

    for (int i = 1; i < N; ++i) {
        double denom = matrixA[i][i] - matrixA[i][i - 1] * c[i - 1];
        c[i] = matrixA[i][i + 1] / denom;
        d[i] = (matrixB[i] - matrixA[i][i - 1] * d[i - 1]) / denom;
    }

    // backward pass
    T[N - 1] = d[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        T[i] = d[i] - c[i] * T[i + 1];
    }
    return T;
}
