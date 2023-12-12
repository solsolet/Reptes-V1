#pragma once
#include <component.hpp>

struct PhysicsComponent : Component {
   struct Data {
      float x{}, y{};
      float vx{}, vy{};
   };
   Data data{};

   static Component::Type getType() noexcept { 
      static auto id { ++numComponentes };
      return id; 
   }
   
   explicit PhysicsComponent(Data d) : data{d} {}
   explicit PhysicsComponent() = default;
   void update(Entity&) final;
};