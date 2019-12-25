#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderSystem.h"
#include "ResourceManager.h"
#include "MovementSystem.h"
#include "Entity.h"

using namespace std;

class GameManager
{
    private:

        bool _running;
        RenderSystem *_renderSystem;
        ResourceManager *_resourceManager;
        MovementSystem *_movementSystem;
        GLFWwindow *_window;

        Entity *entity;

        // VertexBuffer *vertexBuffer;

        GameManager(bool running);
        ~GameManager();
    
    public:
        void runGameLoop();

        static GameManager& getGameManager();
        static void destroyGameManager();
};

#endif