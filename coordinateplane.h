#ifndef COORDINATEPLANE_H
#define COORDINATEPLANE_H

#include <QGraphicsItem>
#include <QPainter>

class CoordinatePlane : public QGraphicsItem
{
public:
    CoordinatePlane( float x, float y, float w, float h);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:

    float x, y, w, h;

};

#endif // COORDINATEPLANE_H
