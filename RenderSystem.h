#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <GL/glut.h>
#include "VertexBuffer.h"

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "ShaderInterface.h"
#include "Entity.h"

using namespace std;

class RenderSystem
{
    private:

        GLFWwindow *_window;

        // vector<ShaderInterface *> *shaderArray;

        RenderSystem();
        ~RenderSystem();

    public:
        void render(Entity * entity);

        static RenderSystem& getRenderSystem();
        static void destroyRenderSystem();

};

#endif