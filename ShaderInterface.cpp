#include "ShaderInterface.h"

GLuint ShaderInterface::getProgramHandle()
{
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_apositionVertex()
{
    return _aPositionVertex;
}

GLint ShaderInterface::get_uColor()
{
    return _uColor;
}

ShaderInterface::ShaderInterface( char *VS, char *FS )
{
    _vertexShaderString = loadTextFromFile(VS);
    _fragmentShaderString = loadTextFromFile(FS);

    shader = new ShaderLoader( _vertexShaderString, _fragmentShaderString );

    free(_vertexShaderString);
    free(_fragmentShaderString);

    _aPositionVertex = glGetAttribLocation( shader->getProgramHandle(), "aPositionVertex" );

    _uColor = glGetUniformLocation( shader->getProgramHandle(), "uColor" );
}

ShaderInterface::~ShaderInterface()
{
    delete shader;
}

char *ShaderInterface::loadTextFromFile(char *file)
{
    FILE *currentFile = fopen(file, "rt");

    // if (!currentFile)
    // {
    //     cout << "file empty" << endl;
    //     return "false";
    // }

    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile);

    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count + 1));
    data[count] = '\0';

    fclose(currentFile);

    return data;
}