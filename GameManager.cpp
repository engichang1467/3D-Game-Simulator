#include "GameManager.h"

GameManager::GameManager(bool running): _running(running), _window(glfwGetCurrentContext()), _renderSystem(&RenderSystem::getRenderSystem())
{

}

GameManager::~GameManager()
{
    RenderSystem::destroyRenderSystem();
}

void GameManager::runGameLoop()
{
    while (_running)
    {
        _running = !glfwWindowShouldClose(_window);

        _renderSystem->render();
    }
}

GameManager& GameManager::getGameManager()
{
    static GameManager *gameManager = NULL;

    if (gameManager == NULL )
    {
        glfwInit();

        glfwWindowHint( GLFW_DEPTH_BITS, 24 );
        glfwWindowHint( GLFW_RED_BITS, 8);
        glfwWindowHint( GLFW_GREEN_BITS, 8);
        glfwWindowHint( GLFW_BLUE_BITS, 8);
        glfwWindowHint( GLFW_ALPHA_BITS, 8);

        GLFWwindow *window = glfwCreateWindow(1280, 720, "My first FPS Game", NULL, NULL);
        glfwMakeContextCurrent(window);


        gameManager = new GameManager(true);

        cout << "GameManager created" << endl;
    }
    return *gameManager;
}

void GameManager::destroyGameManager()
{
    GameManager *gameManager = &getGameManager();

    // if (gameManager != NULL)
    delete gameManager;
    
    cout << "GameManager destroyed" << endl;

    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}