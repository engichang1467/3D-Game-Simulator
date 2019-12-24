#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include "VertexBuffer.h"
#include "Vector3.h"
#include <vector>

using namespace std;

class Entity
{
    private:
        VertexBuffer *_vertexBuffer;

        Vector3 _position;

    public:

        VertexBuffer *getVertexBuffer();
        void setVertexBuffer(VertexBuffer *newVertexBuffer);

        Vector3 getPosition();
        void setPosition(Vector3 newPosition);

        Entity(VertexBuffer *vertexBuffer, Vector3 position);
        ~Entity();
};

#endif // ENTITY_H
