#pragma once
#include <physicscomponent.hpp>
#include <rendercomponent.hpp>

struct Entity {
   RenderComponent*  ren{};
   PhysicsComponent* phy{};
};