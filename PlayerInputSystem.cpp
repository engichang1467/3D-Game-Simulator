#include "PlayerInputSystem.h"

void PlayerInputSystem::setCurrentPlayer(Entity *newPlayer)
{
    _currentPlayer = newPlayer;  
    _eyeVector = normalizeVector3(newPlayer->getEyeVector()); 
}
PlayerInputSystem::PlayerInputSystem(): _window(glfwGetCurrentContext())
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

void PlayerInputSystem::update()
{
    if ( _currentPlayer != NULL && glfwGetInputMode( _window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
    {
        // Press 'W' to move forward
        if (glfwGetKey( _window, GLFW_KEY_W))
        {
            _currentPlayer->setPosition(addVector3(_currentPlayer->getPosition(), 
            scalerMultiplyVector3(_eyeVector, 0.07f)));
        }
        // Press 'S' to move backward
        if (glfwGetKey( _window, GLFW_KEY_S))
        {
            _currentPlayer->setPosition(subtractVector3(_currentPlayer->getPosition(), 
            scalerMultiplyVector3(_eyeVector, 0.07f)));
        }

        _currentPlayer->setEyeVector(addVector3(_currentPlayer->getPosition(), _eyeVector));
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