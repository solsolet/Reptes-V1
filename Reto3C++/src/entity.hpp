#pragma once

// Fordward declaration
struct RenderComponent;
struct PhysicsComponent;

struct Entity {
   RenderComponent*  ren{};
   PhysicsComponent* phy{};
};