#ifndef GRAPHINGSCENE_H
#define GRAPHINGSCENE_H

#include <QGraphicsScene>
#include "coordinateplane.h"

class GraphingScene : public QGraphicsScene
{
public:
    GraphingScene(QObject *parent, float x, float y, float w, float h);

    void graphAngularFreqForLength(float pendulumLength);
    void graphAngularFreqForGravity(float gravity);
    void graphAngularFreqForMass(float mass);

private:

    float x, y, w, h;

    CoordinatePlane* coordPlane;

    float angularFrequency;

};

#endif // GRAPHINGSCENE_H
