#pragma once
#include <raylib.h>

struct Entity;

struct PhysicsComponent{
   float x{}, y{};
   float vx{}, vy{};
 
   void update(Entity& e);
};