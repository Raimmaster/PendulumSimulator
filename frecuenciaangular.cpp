#include "frecuenciaangular.h"

#include <cmath>

#define PLANE_TO_PIXELS 25/5

#include <QDebug>

FrecuenciaAngular::FrecuenciaAngular(float x, float y, float w, float h)
{
    this->x = x, this->y = y, this->w = w, this->h = h;

    clear();
}

void FrecuenciaAngular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(variable < GRAVITY || variable > PERIOD) return;

    bool add = startPoint < endPoint;

    if(!add) skip *= -1;

    QPen pen;
    pen.setColor(QColor(Qt::red));
    pen.setWidth(2);
    painter->setPen(pen);

    QPainterPath path;

    for(float i = startPoint; i <= endPoint; i += skip)
    {
            if( abs(endPoint - skip) < skip)
                i = endPoint;

            float angularFreq = 0;

            if(variable == GRAVITY)
                angularFreq = sqrt(i/length) * frequency;

            else if(variable == LENGTH)
                angularFreq = sqrt(gravity/i) * frequency;

            else if(variable == FREQUENCY)
                angularFreq = sqrt(gravity/length) * i;

            else if(variable == PERIOD)
                angularFreq = sqrt(gravity/length) * (1/i);
            else if (variable == SINUSOIDAL){
                angularFreq = endPoint * sin(sqrt(gravity/length)) * i;
            }


            float x = (i > 0 ? (w/2)+(i*PLANE_TO_PIXELS) : i*PLANE_TO_PIXELS);
            float y = (angularFreq > 0 ? angularFreq*PLANE_TO_PIXELS :  (h/2) + (angularFreq*PLANE_TO_PIXELS) );

            if(i == startPoint)
                path.moveTo(x, y);

            else
            path.lineTo(x, y);

            painter->drawPath(path);
    }

}

/**
 * @brief FrecuenciaAngular::paintSinusoidal - Debe de graficar sinuosoidalmente
 * el movimiento de un péndulo. Usa la ecuación theta = theta_max * sen(sqrt(g/L))*t
 * donde g es gravedad, L longitud, y t el tiempo
 * @param painter
 * @param option
 * @param widget
 */
void FrecuenciaAngular::paintSinusoidal(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

QRectF FrecuenciaAngular::boundingRect() const
{
    return QRectF(x, y, w, h);
}

/**
 * @brief FrecuenciaAngular::set
 * @param g - Gravedad
 * @param f - Frecuencia
 * @param l - Longitud
 * @param p - Periodo
 * @param s - Cantidad de puntos a dar en escala
 * @param sp - Punto inicial
 * @param ep - Punto final
 * @param v - En función a
 */
void FrecuenciaAngular::set(float g, float f, float l, float p, float s, float sp, float ep, int v)
{
    gravity = g;
    frequency = f;
    length = l;
    period = p;
    skip = s;
    startPoint = sp;
    endPoint = ep;

    variable = v;
}

void FrecuenciaAngular::clear()
{
    gravity = frequency = length = period =  skip = startPoint = endPoint = 0;
    variable = -1;
}
