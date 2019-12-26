#ifndef PLAYERINPUTSYSTEM_H
#define PLAYERINPUTSYSTEM_H

#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

class PlayerInputSystem
{
    private:
        PlayerInputSystem();
        ~PlayerInputSystem();

        void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods );

    public:

        static PlayerInputSystem &getPlayerInputSystem();
        static void destroyPlayerInputSystem();

        static void keyCallbackFun(GLFWwindow *window, int key, int scancode, int action, int mods );
};

#endif // PLAYERINPUTSYSTEM_H