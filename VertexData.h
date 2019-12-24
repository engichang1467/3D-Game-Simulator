#ifndef VERTEXDATA_H
#define VERTEXDATA_H

#include "Vector3.h"

typedef struct
{
    Vector3 positionCoordinates;
} VertexDataP;

typedef struct 
{
    Vector3 positionCoordinates;
    Vector3 normalCoordinates;
} VertexDataPN;


#endif //VERTEXDATA_H