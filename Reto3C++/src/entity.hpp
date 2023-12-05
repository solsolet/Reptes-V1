#pragma once
#include <unordered_map>
#include <component.hpp>
#include <physicscomponent.hpp>
#include <rendercomponent.hpp>
// Forward declaration
//struct RenderComponent;

struct Entity {
   //primera manera
   void addComponent(RenderComponent& cmp) {
      ren = &cmp;
   }
   void addComponent(PhysicsComponent& cmp) {
      components[PhysicsComponent::getType()] = &cmp;
   }

   RenderComponent const* getComponent(RenderComponent) const noexcept { return ren; }
   RenderComponent*       getComponent(RenderComponent)       noexcept { return ren; }
   PhysicsComponent*      getComponent(PhysicsComponent)      noexcept {
      return static_cast<PhysicsComponent*>(components[PhysicsComponent::getType()]);
   }
   PhysicsComponent const* getComponent(PhysicsComponent) const noexcept {
      return static_cast<PhysicsComponent*>(
         components.at(PhysicsComponent::getType())
      );
   }
   //si està ací evita que accedim als components
   void update(){
      for( auto& [_, c] : components ) {
         c->update(*this); //el objecte al que apunta (operación e indirección)
      }
   }

   //manera meua abans
   /* template<typename T>
      bool hasComponent(T* cmp) noexcept{
      }

   template<typename T>
      void addComponent(T* cmp) noexcept{
         if (cmp.hasComponent)
            //añade
      }

   template<typename T>
      T* getComponent(T* cmp) noexcept{
      } */
private:
   RenderComponent*  ren{};
   std::unordered_map<Component::Type, Component*> components{};
};