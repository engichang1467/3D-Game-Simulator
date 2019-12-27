#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct {

    GLfloat x, y, z;

} Vector3;

Vector3 makeVector3( GLfloat x, GLfloat y, GLfloat z );
Vector3 addVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 subtractVector3(Vector3 vectorA, Vector3 vectorB);

// Convert the length of our vector into 1
Vector3 normalizeVector3(Vector3 vector);
Vector3 scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue);

#endif // VECTOR3_H