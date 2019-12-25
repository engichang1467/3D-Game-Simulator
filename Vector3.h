#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct {

    GLfloat x, y, z;

} Vector3;

Vector3 makeVector3( GLfloat x, GLfloat y, GLfloat z );
Vector3 addVector3(Vector3 vectorA, Vector3 vectorB);

#endif // VECTOR3_H