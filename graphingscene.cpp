#include "graphingscene.h"

#include <QDebug>

GraphingScene::GraphingScene(QObject *parent, float x, float y, float w, float h) :
     QGraphicsScene::QGraphicsScene(parent)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    setSceneRect(x, y, w, h);

    this->coordPlane = new CoordinatePlane(x, y, w, h);
    this->freqAngular = new FrecuenciaAngular(x, y, w, h);
    addItem(coordPlane);
    addItem(freqAngular);
}

void GraphingScene::graphAngularFreqForLength(float lengthI, float lengthF, float skip, float gravity, float freq)
{
     freqAngular->set(gravity, freq, 0, 0, skip, lengthI, lengthF, LENGTH);
     freqAngular->update(x, y, w, h);
     update(x, y, w, h);
}

void GraphingScene::graphAngularFreqForGravity(float gravityI, float gravityF, float skip, float length, float freq)
{
     freqAngular->set(0, freq, length, 0, skip, gravityI, gravityF, GRAVITY);
     freqAngular->update(x, y, w, h);
     update(x, y, w, h);
}

void GraphingScene::graphAngularFreqForFreq(float freqI, float freqF, float skip, float length, float gravity)
{
     freqAngular->set(gravity, 0, length, 0, skip, freqI, freqF, FREQUENCY);
     freqAngular->update(x, y, w, h);
     update(x, y, w, h);
}

void GraphingScene::graphAngularFreqForPeriod(float periodI, float periodF, float skip, float length, float gravity)
{
      freqAngular->set(gravity, 0, length, 0, skip, periodI, periodF, PERIOD);
      freqAngular->update(x, y, w, h);
      update(x, y, w, h);
}
