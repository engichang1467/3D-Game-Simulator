#ifndef MATRIX3_H
#define MATRIX3_H

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct 
{
    GLfloat m00, m01, m02;
    GLfloat m10, m11, m12;
    GLfloat m20, m21, m22;
} Matrix3;

Matrix3 scalerMultiplyMatrix3( Matrix3 matrix, GLfloat scalerValue);
Matrix3 addMatrix3( Matrix3 matrixA, Matrix3 matrixB);
Matrix3 makeRotationMatrix3( GLfloat angle, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis );

const Matrix3 identityMatrix3 = { 1.0f, 0.0f, 0.0f,
                                  0.0f, 1.0f, 0.0f,
                                  0.0f, 0.0f, 1.0f };

#endif // MATRIX3_H