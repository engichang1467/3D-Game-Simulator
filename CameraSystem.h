#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

#include <iostream>
#include "Entity.h"


class CameraSystem
{
    private:

        Entity *_currentCamera;

        CameraSystem();
        ~CameraSystem();
    
    public:

        Entity *getCurrentCamera();
        void setCurrentCamera(Entity *newCamera);

        static CameraSystem &getCameraSystem();
        static void destroyCameraSystem();
};

#endif // CAMERASYSTEM_H