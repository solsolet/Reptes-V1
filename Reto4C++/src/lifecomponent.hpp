#pragma once
#include <component.hpp>

struct LifeComponent : Component {
   struct Data {
      uint32_t life{100};
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