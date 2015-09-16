#ifndef PENDULO_H
#define PENDULO_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct forza{
    double fx;
    double fy;
};

struct data{
    vector<double> x;
    vector<double> y;
};

class Pendulo
{
public:
    Pendulo();
    //forza fuerza_alterna;
    const static double GRAVEDAD = 9.8;//metros entre segundos
    const double PI = 3.14159;
    double longitud;//del péndulo
    double amortiguamiento;
    double frecuencia; //de la fuerza impulsadora
    double theta, omega;
    double a, b, N, h;

    data vectorgetData();
private:
    vector<double> arange(double start, double stop, double step);
    double deg2rad(double degs);
    forza funcion(forza r, double t);
    //        k1 = h*f(r,t)
    //        k2 = h*f(r+0.5*k1,t+0.5*h)
    //        k3 = h*f(r+0.5*k2,t+0.5*h)
    //        k4 = h*f(r+k3,t+h)
    //        r = r+(k1+2*k2+2*k3+k4)/6
    forza suma(forza f1, forza f2);
    forza suma(forza f1, double v1);
    forza multi(forza f1, forza f2);
    forza multi(forza f1, double v1);
    forza divi(forza f1, double v1);


};

#endif // PENDULO_H
