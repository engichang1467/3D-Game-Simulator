#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H


#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderInterface.h"

class VertexBuffer
{
    private:
        GLuint _vertexBufferID;
        ShaderInterface *_shader;

        GLenum _mode;
        GLsizei _count; // # of vertices
        GLsizei _stride;
        GLvoid *_positionOffset;
        GLvoid *_normalOffset;

    public:
        
       GLuint getVertexBufferID();
       ShaderInterface *getShader();
         
       VertexBuffer( const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride, ShaderInterface *shader, GLvoid *positionOffset, GLvoid *normalOffset);
       ~VertexBuffer();

       void configureVertexAttributes();
       void renderVertexbuffer();


};

#endif // VertexBuffer