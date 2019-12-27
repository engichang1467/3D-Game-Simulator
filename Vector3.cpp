#include "Vector3.h"
#include <math.h>

Vector3 makeVector3( GLfloat x, GLfloat y, GLfloat z )
{
    Vector3 newVector;

    newVector.x = x;
    newVector.y = y;
    newVector.z = z;

    return newVector;
}

Vector3 addVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 newVector;
    newVector.x = vectorA.x + vectorB.x;
    newVector.y = vectorA.y + vectorB.y;
    newVector.z = vectorA.z + vectorB.z;

    return newVector;
}

Vector3 subtractVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 newVector;
    newVector.x = vectorA.x - vectorB.x;
    newVector.y = vectorA.y - vectorB.y;
    newVector.z = vectorA.z - vectorB.z;

    return newVector;
}

Vector3 normalizeVector3(Vector3 vector)
{
    GLdouble length = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);

    Vector3 unitVector;
    unitVector.x = vector.x / length;
    unitVector.y = vector.y / length;
    unitVector.z = vector.z / length;

    return unitVector;
}

Vector3 scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue)
{
    Vector3 newVector;
    newVector.x = vectorToMultiply.x * scalerValue;
    newVector.y = vectorToMultiply.y * scalerValue;
    newVector.z = vectorToMultiply.z * scalerValue;

    return newVector;
}