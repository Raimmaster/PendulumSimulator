#ifndef GRAPHINGSCENE_H
#define GRAPHINGSCENE_H

#include <QGraphicsScene>
#include "coordinateplane.h"
#include "frecuenciaangular.h"

class GraphingScene : public QGraphicsScene
{
public:
    GraphingScene(QObject *parent, float x, float y, float w, float h);

    void graphAngularFreqForLength(float lengthI, float lengthF, float skip, float gravity, float freq);
    void graphAngularFreqForGravity(float gravityI, float gravityF, float skip, float length, float freq);
    void graphAngularFreqForFreq(float freqI, float freqF, float skip, float length, float gravity);
    void graphAngularFreqForPeriod(float periodI, float periodF, float skip, float length, float gravity);

private:

    float x, y, w, h;

    CoordinatePlane* coordPlane;
    FrecuenciaAngular* freqAngular;

};

#endif // GRAPHINGSCENE_H
