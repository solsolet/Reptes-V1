#pragma once
#include <component.hpp>

struct PhysicsComponent : Component {
   struct Data {
      float x{}, y{};
      float vx{}, vy{};
   };
   Data data{};

   static Component::Type getType() noexcept {
      static auto id { ++numComponentes }; //es diu PhysicsComponent getType id
      return id;
   }

   explicit PhysicsComponent(Data d) : data{d} {} //contructor
   explicit PhysicsComponent() = default;         //constructor por defecto
   void update(Entity&) final;
};