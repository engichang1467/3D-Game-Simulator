#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H


#include <GLFW/glfw3.h>
#include <iostream>

class VertexBuffer
{
    private:
        GLuint _vertexBufferID;

        GLenum _mode;
        GLsizei _count; // # of vertices
        GLsizei _stride;

    public:
        
       GLuint getVertexBufferID();
         
       VertexBuffer( const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride);
       ~VertexBuffer();

       void configureVertexAttributes(GLint vertexPosition);
       void renderVertexbuffer();


};

#endif // VertexBuffer