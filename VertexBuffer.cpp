#include "VertexBuffer.h"

GLuint VertexBuffer::getVertexBufferID()
{
    return _vertexBufferID;
}

VertexBuffer::VertexBuffer( const GLvoid *data, GLsizeiptr size)
{
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer( GL_ARRAY_BUFFER, _vertexBufferID );
    glBufferData( GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW );
}


VertexBuffer::~VertexBuffer()
{
     glDeleteBuffers(1, &_vertexBufferID);
     _vertexBufferID = 0;
}