#pragma once

struct PhysicsComponent{
   float x{}, y{};
   float vx{}, vy{};
 
   void update() {
      x += vx;
      y += vy;
   }
};