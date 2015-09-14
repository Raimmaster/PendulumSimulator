#include "graphingscene.h"

GraphingScene::GraphingScene(QObject *parent, float x, float y, float w, float h) :
     QGraphicsScene::QGraphicsScene(parent)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    this->angularFrequency = 0;

    setSceneRect(x, y, w, h);

    this->coordPlane = new CoordinatePlane(x, y, w, h);
    addItem(coordPlane);
}
