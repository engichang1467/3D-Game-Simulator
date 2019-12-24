#include "GameManager.h"

// GLfloat vertices[] = {
//     -0.5f, -0.5f, 0.0f,
//      0.5f, -0.5f, 0.0f,
//      0.0f,  0.5f, 0.0f
// };

GameManager::GameManager(bool running): _running(running), _window(glfwGetCurrentContext()), _renderSystem(&RenderSystem::getRenderSystem()), _resourceManager(&ResourceManager::getResourceManager())
{
    // vertexBuffer = new VertexBuffer(vertices, sizeof(vertices), GL_TRIANGLES, 3, sizeof(GLfloat)*3);
    entity = new Entity( _resourceManager->getVertexBufferArray()->at(1), makeVector3(0.0f, 0.0f, 0.0f));
}

GameManager::~GameManager()
{
    ResourceManager::destroyResourceManager();
    RenderSystem::destroyRenderSystem();
}

void GameManager::runGameLoop()
{
    while (_running)
    {
        _running = !glfwWindowShouldClose(_window);

        _renderSystem->render( entity );
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
        glfwWindowHint( GLFW_SAMPLES, 16);

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