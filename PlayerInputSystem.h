#ifndef PLAYERINPUTSYSTEM_H
#define PLAYERINPUTSYSTEM_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "Entity.h"

using namespace std;

class PlayerInputSystem
{
    private:

        Vector3 _eyeVector;
        GLFWwindow *_window;
        Entity *_currentPlayer;

        PlayerInputSystem();
        ~PlayerInputSystem();


        void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods );

    public:

        void setCurrentPlayer(Entity *newPlayer);

        void update();

        static PlayerInputSystem &getPlayerInputSystem();
        static void destroyPlayerInputSystem();

        static void keyCallbackFun(GLFWwindow *window, int key, int scancode, int action, int mods );
};

#endif // PLAYERINPUTSYSTEM_H