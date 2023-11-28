#include "physicscomponent.hpp"
#include <raylib.h>

struct Entity;

void 
PhysicsComponent::update(Entity&) {
   x += vx;
   y += vy;
}