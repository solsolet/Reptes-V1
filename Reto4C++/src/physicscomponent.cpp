#include "physicscomponent.hpp"

struct Entity;

void 
PhysicsComponent::update(Entity&) {
   data.x += data.vx;
   data.y += data.vy;
}