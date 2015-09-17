#ifndef FRECUENCIAANGULAR_H
#define FRECUENCIAANGULAR_H

#include <QGraphicsItem>
#include <QPainter>

enum Variables
{
       GRAVITY, FREQUENCY, LENGTH, PERIOD, SINUSOIDAL
};

class FrecuenciaAngular : public  QGraphicsItem
{
public:
    FrecuenciaAngular(float x, float y, float w, float h);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void paintSinusoidal(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void set(float g, float f, float l, float p, float s, float sp, float ep, int v);

    void clear();

private:

    float x, y, w, h;

    float gravity,
              frequency,
              length,
              period,
              skip,
              startPoint,
              endPoint;

    int variable;
};

#endif // FRECUENCIAANGULAR_H
