#pragma once
#include <unordered_map>
#include <component.hpp>
// Forward declaration
struct RenderComponent;
struct PhysicsComponent;

struct Entity {
   RenderComponent*  ren{};
   std::unordered_map<Component::Type, Component*> components{};
};