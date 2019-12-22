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

        GLenum _mode;
        GLsizei _count, _stride;

    public:
        
       GLuint getVertexBufferID();
         
       VertexBuffer( const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride);
       ~VertexBuffer();

       void configureVertexAttributess(GLint vertexPosition);
       void renderVertexBuffer();

};

#endif // VertexBuffer