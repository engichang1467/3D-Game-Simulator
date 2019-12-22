#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <GLFW/glfw3.h>
#include <iostream>

class RenderSystem
{
    private:

        GLFWwindow *_window;

        RenderSystem();
        ~RenderSystem();

    public:
        void render();

        static RenderSystem& getRenderSystem();
        static void destroyRenderSystem();

};

#endif