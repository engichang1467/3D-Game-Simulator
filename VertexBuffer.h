#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>

class VertexBuffer
{
    private:
        GLuint _vertexBufferID;

    public:
        
       GLuint getVertexBufferID();
         
       VertexBuffer( const GLvoid *data, GLsizeiptr size);
       ~VertexBuffer();

};

#endif // VertexBuffer