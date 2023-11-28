#pragma once
#include <raylib.h>

struct PhysicsComponent{
   float x{}, y{};
   float vx{}, vy{};
 
   void update() {
      x += vx;
      y += vy;
   }
};