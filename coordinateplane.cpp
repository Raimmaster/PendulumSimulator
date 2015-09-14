#include "coordinateplane.h"
#include <QGraphicsScene>

CoordinatePlane::CoordinatePlane(float x, float y, float w, float h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h= h;
}

void CoordinatePlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(0, h/2, w, h/2);
    painter->drawLine(w/2, 0, w / 2, h);

    int markerL = 10;
    int interval = 25;

    for(int i = 0; i <= h; i+=interval)
    {
        if(i == h/2) continue;

        painter->drawLine( (w/2) - markerL, i, (w/2) + markerL,  i);
    }

    for(int i =0; i <= w; i+=interval)
    {
        if(i == w/2) continue;

         painter->drawLine( i, (h/2) - markerL, i,  (h/2) + markerL);
    }

}

QRectF CoordinatePlane::boundingRect() const
{
    return QRectF(x, y, w, h);
}
