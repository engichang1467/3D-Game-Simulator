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
#include "CameraSystem.h"

using namespace std;

class RenderSystem
{
    private:

        GLFWwindow *_window;

        CameraSystem *_cameraSystem;
        Entity *_currentCamera;

        // vector<ShaderInterface *> *shaderArray;

        RenderSystem();
        ~RenderSystem();

    public:

        Entity *getCurrentCamera();
        void setCurrentCamera(Entity *newCamera);

        void render(vector<Entity *> *entityArray);

        static RenderSystem& getRenderSystem();
        static void destroyRenderSystem();

};

#endif