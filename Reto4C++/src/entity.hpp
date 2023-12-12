#pragma once
#include <unordered_map>
#include <component.hpp>
#include <physicscomponent.hpp>
#include <rendercomponent.hpp>

// Forward declaration
//struct RenderComponent;

struct Entity {

   void addComponent(RenderComponent& cmp) {
      ren = &cmp;
   }
   void addComponent(PhysicsComponent& cmp) {
      components[PhysicsComponent::getType()] = &cmp;
   }
   RenderComponent const* getComponent(RenderComponent) const noexcept { return ren; }
   RenderComponent*       getComponent(RenderComponent)       noexcept { return ren; }
   PhysicsComponent*      getComponent(PhysicsComponent)      noexcept { 
      auto const pid = PhysicsComponent::getType();
      if (components.contains(pid)) 
         return static_cast<PhysicsComponent*>(components[pid]);
      return nullptr;
   }
   PhysicsComponent const* getComponent(PhysicsComponent) const noexcept { 
      auto const pid = PhysicsComponent::getType();
      if (components.contains(pid)) 
         return static_cast<PhysicsComponent*>(components.at(pid));
      return nullptr;
   }


   void update() {
      for( auto& [_, c] : components ) {
         c->update(*this); 
      }
   }

   bool              alive{true};
private:
   RenderComponent*  ren{};
   std::unordered_map<Component::Type, Component*> components{};
};