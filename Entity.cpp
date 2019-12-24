#include "Entity.h"

VertexBuffer *Entity::getVertexBuffer()
{
    return _vertexBuffer;
}

void Entity::setVertexBuffer(VertexBuffer *newVertexBuffer)
{
    _vertexBuffer = newVertexBuffer;
}

Vector3 Entity::getPosition()
{
    return _position;
}

void Entity::setPosition(Vector3 newPosition)
{
    _position = newPosition;
}

Entity::Entity(VertexBuffer *vertexBuffer, Vector3 position): _vertexBuffer(vertexBuffer), _position(position) 
{
    
}

Entity::~Entity()
{

}