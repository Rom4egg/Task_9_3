#include <iostream>
#include <cmath>
#include <vector>

double g(double x, double y) {
    return 1000 * (1 - y * y) * y - x;
}

std::vector<double> Class_RK(double Tk, double x0, double y0, int N) {
    double h = Tk / N;
    std::vector<double> x;
    x.resize(N);
    std::vector<double> y;
    y.resize(N);
    x[0] = x0;
    y[0] = y0;
    double k1, k2, k3, k4, m1, m2, m3, m4;
    for (int i = 1; i < N; i++) {
        k1 = y[i - 1];
        m1 = g(x[i - 1], y[i - 1]);
        k2 = y[i - 1] + m1 * h / 2;
        m2 = g(x[i - 1] + k1 * h / 2, y[i - 1] + m1 * h / 2);
        k3 = y[i - 1] + m2 * h / 2;
        m3 = g(x[i - 1] + k2 * h / 2, y[i - 1] + m2 * h / 2);
        k4 = y[i - 1] + m3 * h;
        m4 = g(x[i - 1] + k3 * h, y[i - 1] + m3 * h);
        x[i] = x[i - 1] + h / 6 * (k1 + 2 * (k2 + k3) + k4);
        y[i] = y[i - 1] + h / 6 * (m1 + 2 * (m2 + m3) + m4);
    }
    return x;
}


int main() {
    int N = 1e6;
    double Tk = 1000;
    double x0 = 0;
    double y0 = 0.001;
    std::vector<double> Res = Class_RK(Tk, x0, y0, N);
    for(int i = 0;i < 100;i++)
        std::cout<<Res[i*1e4]<<std::endl;
    return 0;
}
