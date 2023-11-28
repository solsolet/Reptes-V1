#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

struct PhysicsComponent{
   float x{}, y{};
   float vx{}, vy{};
 
   void update() {
      x += vx;
      y += vy;
   }
};

#endif