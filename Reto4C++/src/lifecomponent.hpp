#pragma once
#include <component.hpp>

struct LifeComponent : Component {
   struct Data {
      float l{};
   };
   Data data{};

   static Component::Type getType() noexcept { 
      static auto id { ++numComponentes };
      return id; 
   }
   
   explicit LifeComponent(Data d) : data{d} {}
   explicit LifeComponent() = default;
   void update(Entity&) final;
};