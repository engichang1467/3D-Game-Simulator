#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderSystem.h"
#include "ResourceManager.h"

using namespace std;

class GameManager
{
    private:

        bool _running;
        RenderSystem *_renderSystem;
        ResourceManager *_resourceManager;
        GLFWwindow *_window;

        VertexBuffer *vertexBuffer;

        GameManager(bool running);
        ~GameManager();
    
    public:
        void runGameLoop();

        static GameManager& getGameManager();
        static void destroyGameManager();
};

#endif