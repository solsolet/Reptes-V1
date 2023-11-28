#include "physicscomponent.hpp"
#include <raylib.h>

struct PhysicsComponent{
   float x{}, y{};
   float vx{}, vy{};
 
   void update() {
      x += vx;
      y += vy;
   }
};