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

        Vector3 _position, _scale, _rotation;

        Vector3 _velocity, _scaleVelocity, _rotationVelocity;

    public:

        VertexBuffer *getVertexBuffer();
        void setVertexBuffer(VertexBuffer *newVertexBuffer);

        Vector3 getPosition();
        void setPosition(Vector3 newPosition);

        Vector3 getScale();
        void setScale(Vector3 newScale);

        Vector3 getRotation();
        void setRotation(Vector3 newRotation);

        Vector3 getVelocity();
        void setVelocity(Vector3 newVelocity);

        Vector3 getScaleVelocity();
        void setScaleVelocity(Vector3 newScaleVelocity);

        Vector3 getRotationVelocity();
        void setRotationVelocity(Vector3 newRotationVelocity);

        Entity(VertexBuffer *vertexBuffer, Vector3 position);
        ~Entity();
};

#endif // ENTITY_H
