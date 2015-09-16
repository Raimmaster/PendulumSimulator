#include "Pendulo.h"

Pendulo::Pendulo()
{

}

forza Pendulo::funcion(forza r, double t){
    double theta = r.fx;
    double omega = r.fy;


    double fx = omega;
    double fy = -1.0 * (GRAVEDAD/longitud) * sin(theta) - amortiguamiento*omega + N*sin(frecuencia*t);
    forza arreglo;
    arreglo.fx = fx;
    arreglo.fy = fy;
    return arreglo;
}

/**Devuelve un vector con valores divididos entre el step indicado
**/
vector<double> Pendulo::arange(double start, double stop, double step){
    double accum = start;
    vector<double> arreglo;
    while(accum < stop){
        arreglo.push_back(accum);
        accum += step;
    }

    return arreglo;
}

double Pendulo::deg2rad(double degs){
    return degs * (PI/180);
}

anim Pendulo::getData(){
    cout<<"estamos aqui"<<endl;
    vector<double> tpuntos = arange(a,b,h);
    vector<double> thetap, omegap;

//    double cinit[2];
//    cinit[0] = theta;
//    cinit[1] = omega;

    forza r;
    r.fx = theta;
    r.fy = omega;
    cout<<"estamos aqui"<<endl;
    for(int x = 0;  x < tpuntos.size(); x++){
        cout<<"\t"<<x<<endl;
        thetap.push_back(r.fx);
        omegap.push_back(r.fy);

        forza k1 = multi(funcion(r,(double)x), h);
        forza k2 = multi(funcion(suma(r, multi(k1, 0.5)), x + 0.5*h),h);
        forza k3 = multi(funcion(suma(r, multi(k2, 0.5)), x+0.5*h),h);
        forza k4 = multi(funcion(suma(r, k3), x+h),h);

        forza p1 = multi(k2, 2);
        forza p2 = multi(k3, 2);
        forza p3 = suma(suma(k1, p1), suma(p2, k4));
        forza p4 = divi(p3, 6);

        r = suma(r, p4);


//        k1 = h*f(r,t)
//        k2 = h*f(r+0.5*k1,t+0.5*h)
//        k3 = h*f(r+0.5*k2,t+0.5*h)
//        k4 = h*f(r+k3,t+h)
//        r = r+(k1+p1+p2+k4)/6


    }

    anim animacion;
    animacion.x = thetap;
    animacion.y = omegap;
    return animacion;
}

forza Pendulo::suma(forza f1, forza f2){
    forza nueva;
    nueva.fx = f1.fx + f2.fx;
    nueva.fy = f1.fy + f2.fy;

    return nueva;
}

forza Pendulo::suma(forza f1, double v1){
    forza nueva;
    nueva.fx = f1.fx + v1;
    nueva.fy = f1.fy + v1;

    return nueva;
}

forza Pendulo::multi(forza f1, forza f2){
    forza nueva;
    nueva.fx = f1.fx * f2.fx;
    nueva.fy = f1.fy * f2.fy;

    return nueva;
}

forza Pendulo::multi(forza f1, double v1){
    forza nueva;
    nueva.fx = f1.fx * v1;
    nueva.fy = f1.fy * v1;

    return nueva;
}

forza Pendulo::divi(forza f1, double v1){
    forza nueva;
    nueva.fx = f1.fx / v1;
    nueva.fy = f1.fy / v1;

    return nueva;
}




/*
 *
from math import sin
from numpy import array,arange
from pylab import plot,xlabel,show

g=9.8#gravedad
l=2.0#longitud del pendulo
q=0.14#amortiguamiento
F=0.6#amplitud de la fuerza impulsora
od=0.5#frecuencia de la fuerza impulsora

def f(r,t):
    theta = r[0]
    omega = r[1]


    fx = omega
    fy = -1.0 * (g/l) * sin(theta) - q*omega + F*sin(od*t)
    return array([fx,fy],float)

a = 0.0 //inicio
b = 80.0 //fin
N = 10000 //fuerza
h = (b-a)/N

tpuntos = arange(a,b,h)
thetapuntos = []
omegapuntos = []

r = array([0.6,0.0],float)#condiciones iniciales ([thetha, omega o velocidad angular])
for t in tpuntos:#met. numerico runge kutta de cuarto orden
    thetapuntos.append(r[0])
    omegapuntos.append(r[1])


    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r = r+(k1+2*k2+2*k3+k4)/6
plot(tpuntos,thetapuntos)

xlabel("x")
show()
*/
