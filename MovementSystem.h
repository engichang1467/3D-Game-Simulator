#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <iostream>
#include "Vector3.h"
#include <GLFW/glfw3.h>
#include "Entity.h"


class MovementSystem
{
    private:

        MovementSystem();
        ~MovementSystem();

    public:

        void update(vector<Entity *> *entityArray);

        static MovementSystem& getMovementSystem();
        static void destroyMovementSystem();

};

#endif // MOVEMENTSYSTEM_H