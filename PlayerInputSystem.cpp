#include "PlayerInputSystem.h"

void PlayerInputSystem::setCurrentPlayer(Entity *newPlayer)
{
    _currentPlayer = newPlayer;  
    _eyeVector = normalizeVector3(newPlayer->getEyeVector()); 
}
PlayerInputSystem::PlayerInputSystem(): _window(glfwGetCurrentContext())
{
    glfwGetCursorPos( _window, &_lastMousePosition.x, &_lastMousePosition.y);
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
    // Press esc to escape
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

    // Vector2 currentMousePosition;
    // glfwGetCursorPos( _window, &currentMousePosition.x, &currentMousePosition.y);

    // _eye
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
        // Press 'A' to move left
        if (glfwGetKey( _window, GLFW_KEY_A))
        {
            _currentPlayer->setPosition(subtractVector3(_currentPlayer->getPosition(), 
            scalerMultiplyVector3(crossProductVector3(_eyeVector, makeVector3(0.0f, 1.0f, 0.0f)), 0.07f)));
        }
        // Press 'D' to move right
        if (glfwGetKey( _window, GLFW_KEY_D))
        {
            _currentPlayer->setPosition(addVector3(_currentPlayer->getPosition(), 
            scalerMultiplyVector3(crossProductVector3(_eyeVector, makeVector3(0.0f, 1.0f, 0.0f)), 0.07f)));
        }

        Vector2 currentMousePosition;
        glfwGetCursorPos( _window, &currentMousePosition.x, &currentMousePosition.y);

        // _eyeVector = transformVector3(_eyeVector, makeRotationMatrix3((3.14f / (4.0f * 45.0f))*-(currentMousePosition.x - _lastMousePosition.x), 0.0f, 1.0f, 0.0f));

        // // glfwGetCursorPos( _window, &_lastMousePosition.x, &_lastMousePosition.y);

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