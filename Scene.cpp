#include "Scene.h"
#include "CameraSystem.h"
#include "ResourceManager.h"

vector<Entity *> *Scene::getChildren()
{
    return _children;
}

Scene::Scene()
{
    _children = new vector<Entity *>();

    ResourceManager *resourceManager = &ResourceManager::getResourceManager();
    Entity *entity = new Entity( resourceManager->getVertexBufferArray()->at(1), makeVector3(0.0f, 0.0f, 0.0f));

    entity->setRotation(makeVector3(90.0f, 0.0f, 0.0f));
    entity->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    // entity->setVelocity(makeVector3(-0.01f, 0.01f, -0.01f));
    // entity->setRotationVelocity(makeVector3(1.0f, 1.0f, 0.0f));
    // entity->setScaleVelocity(makeVector3(0.01f, 0.0f, 0.0f));

    _children->push_back(entity);

    Entity *camera = new Entity(NULL, makeVector3(1.0f, 1.0f, 2.0f));
    camera->setEyeVector(makeVector3(0.0f, 0.0f, 0.0f));
    camera->setVelocity(makeVector3(0.0f, 0.0f, 0.01f));

    _children->push_back(camera);

    CameraSystem *cameraSystem = &CameraSystem::getCameraSystem();
    cameraSystem->setCurrentCamera(camera);

}

Scene::~Scene()
{
    for (vector<Entity *>::iterator iterator = _children->begin(); iterator != _children->end(); iterator++)
    {
        delete *iterator;
    }

    delete _children;
}