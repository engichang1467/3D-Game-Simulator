#ifndef SHADERINTERFACE_H
#define SHADERINTERFACE_H

#include <iostream>
#include "ShaderLoader.h"

class ShaderInterface
{
    private:

        ShaderLoader *shader;

        GLint _aPositionVertex;
        GLint _uColor;

        char *_vertexShaderString;
        char *_fragmentShaderString;

        char *loadTextFromFile( char *file);

    public:

        GLuint getProgramHandle();
        GLint get_aPositionVertex();
        GLint get_uColor();

        ShaderInterface(char *VS, char *FS);
        ~ShaderInterface();

};

#endif // SHADERINTERFACE_H