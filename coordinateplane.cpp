#include "coordinateplane.h"
#include <QGraphicsScene>

#include <sstream>

#define PIXELS_TO_PLANE 5/25

using std::stringstream;
using std::string;

CoordinatePlane::CoordinatePlane(float x, float y, float w, float h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h= h;
}

void CoordinatePlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Eje X
    painter->drawLine(0, h/2, w, h/2);

    //Eje Y
    painter->drawLine(w/2, 0, w / 2, h);

    //En Pixels

    int markerL = 10; // Longitud de cada marcador
    int interval = 25;  // Distancia en pixeles entre cada marcador

    //En Plane Units

    int top = 50; // Magnitud maxima en el eje Y, en unidades de plano
    int right = 50; // Magnitud maxima en el eje X, en unidades de plano
    int _interval = 5; // Intervalo o 'skip' entre cada marcador, en unidades de plano

    // Marcadores en el eje Y
    for(int i = 0, k = top; i <= h; i+=interval, k-=_interval)
    {
        if(i == h/2) continue;

        stringstream strm("");
        string str("");
        strm << k;
        strm >> str;


        // Marcador
        painter->drawLine( (w/2) - markerL, i, (w/2) + markerL,  i);

        // Coordenada en Y
        painter->drawText((w/2) + markerL + 5, i + 5, QString(str.c_str()));
    }

    // Marcadores en el eje X
    for(int i =0, k = -1*right; i <= w; i+=interval, k += _interval)
    {
        if(i == w/2) continue;

        stringstream strm("");
        string str("");
        strm << k;
        strm >> str;

        // Marcador
         painter->drawLine( i, (h/2) - markerL, i,  (h/2) + markerL);

         //  Coordenada en X
         painter->drawText(i,  (h/2) + markerL + 13, QString(str.c_str()));
    }

}

QRectF CoordinatePlane::boundingRect() const
{
    return QRectF(x, y, w, h);
}
