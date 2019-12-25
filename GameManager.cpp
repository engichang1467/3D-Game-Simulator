#include "GameManager.h"

// GLfloat vertices[] = {
//     -0.5f, -0.5f, 0.0f,
//      0.5f, -0.5f, 0.0f,
//      0.0f,  0.5f, 0.0f
// };

GameManager::GameManager(bool running): 
_running(running), _window(glfwGetCurrentContext()), 
_renderSystem(&RenderSystem::getRenderSystem()), 
_resourceManager(&ResourceManager::getResourceManager()),
_movementSystem(&MovementSystem::getMovementSystem())
{
    // vertexBuffer = new VertexBuffer(vertices, sizeof(vertices), GL_TRIANGLES, 3, sizeof(GLfloat)*3);
    entity = new Entity( _resourceManager->getVertexBufferArray()->at(1), makeVector3(0.0f, 0.0f, 0.0f));
    entity->setRotation(makeVector3(90.0f, 0.0f, 0.0f));
    entity->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    entity->setVelocity(makeVector3(-0.01f, 0.01f, -0.01f));
    entity->setRotationVelocity(makeVector3(1.0f, 1.0f, 0.0f));
    entity->setScaleVelocity(makeVector3(0.01f, 0.0f, 0.0f));
}

GameManager::~GameManager()
{
    ResourceManager::destroyResourceManager();
    RenderSystem::destroyRenderSystem();
}

#define Updates_Per_Sceond 60.0f

void GameManager::runGameLoop()
{
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;

    while (_running)
    {
        double currentTime = glfwGetTime();
        deltaTime += (currentTime - lastTime) * Updates_Per_Sceond;
        lastTime = currentTime;

        while (deltaTime >= 1.0f)
        {
            _running = !glfwWindowShouldClose(_window);

            _movementSystem->update( entity );

            --deltaTime;
        }


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
        glfwWindowHint( GLFW_RESIZABLE, GL_FALSE);

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