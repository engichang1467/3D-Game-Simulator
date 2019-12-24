#ifndef SHADERDATA_H
#define SHADERDATA_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "Vector3.h"
#include "Vector4.h"

class ShaderData
{
    private:
        Vector4 _uColorValue;
        Vector3 _uLightPosition;

    public:

        Vector4 get_uColorValue();
        void set_uColorValue(Vector4 newColor);

        Vector3 get_uLightPosition();
        void set_uLightPosition(Vector3 newPosition);

        ShaderData(Vector4 newColor, Vector3 newPosition);
        ~ShaderData();
};

#endif // SHADERDATA_H