#include "ShaderData.h"


void ShaderData::set_uColorValue(Vector4 newColor)
{
    _uColorValue = newColor;
}

Vector4 ShaderData::get_uColorValue()
{
    return _uColorValue;
}

void ShaderData::set_uLightPosition(Vector3 newPosition)
{
    _uLightPosition = newPosition;
}

Vector3 ShaderData::get_uLightPosition()
{
    return _uLightPosition;
}

ShaderData::ShaderData(Vector4 newColor, Vector3 newPosition): _uColorValue(newColor), _uLightPosition(newPosition)
{

}

ShaderData::~ShaderData()
{

}