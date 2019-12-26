#include "PlayerInputSystem.h"

PlayerInputSystem::PlayerInputSystem()
{

}
PlayerInputSystem::~PlayerInputSystem()
{

}

void PlayerInputSystem::keyCallback( GLFWwindow *window, 
                                     int key, 
                                     int scancode, 
                                     int action, 
                                     int mods )
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    { 
        if (GLFW_CURSOR_DISABLED == glfwGetInputMode(glfwGetCurrentContext(), GLFW_CURSOR))
        {
            glfwSetInputMode( glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }
        else 
        {
            glfwSetInputMode( glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
    }
}                                        

void PlayerInputSystem::keyCallbackFun( GLFWwindow *window, 
                                        int key, 
                                        int scancode, 
                                        int action, 
                                        int mods )
{
    PlayerInputSystem *playerInputSystem  = &getPlayerInputSystem();
    playerInputSystem->keyCallback(window, key, scancode, action, mods);
}

PlayerInputSystem &PlayerInputSystem::getPlayerInputSystem()
{
    static PlayerInputSystem *playerInputSystem = NULL;  

    if (playerInputSystem == NULL)
    {
        // this function will be called if player press a keyboard
        glfwSetKeyCallback( glfwGetCurrentContext(), *keyCallbackFun);
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        playerInputSystem = new PlayerInputSystem();
    }
    
    return *playerInputSystem;
}
void PlayerInputSystem::destroyPlayerInputSystem()
{
    PlayerInputSystem *playerInputSystem = &getPlayerInputSystem();
    delete playerInputSystem;
}