#ifndef PENDULO_H
#define PENDULO_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct forza{
    float fx;
    float fy;
};

class Pendulo
{
public:
    Pendulo();
    forza fuerza_alterna;
    const static double GRAVEDAD = 9.8;//metros entre segundos
    const double PI = 3.14159;
    double longitud;//del péndulo
    double amortiguamiento;
    double fuerza_impulsadora;
    double frecuencia; //de la fuerza impulsadora
private:
    vector<double> arange(double start, double stop, double step);
    double deg2rad(double degs);

};

#endif // PENDULO_H
