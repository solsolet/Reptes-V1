#pragma once
#include <component.hpp>

struct PhysicsComponent : Component {
   struct Data {
      float x{}, y{};
      float vx{}, vy{};
   };
   Data data{};

   constexpr static Component::Type getType() noexcept { return 1; }

   explicit PhysicsComponent(Data d) : data{d} {}
   void update(Entity&) final;
};