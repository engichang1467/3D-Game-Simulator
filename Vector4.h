#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct {
    GLfloat x, y, z, w;
} Vector4;

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#endif // VECTOR4_H