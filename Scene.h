#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "Entity.h"
#include <vector>

using namespace std;

class Scene
{
    private:
        vector<Entity *> *_children;

    public:
        vector<Entity *> *getChildren();

        Scene();
        ~Scene();
};

#endif // SCENE_H