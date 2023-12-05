#pragma once
#include <cstdint>
#include <raylib.h>
#include <component.hpp>

//extern uint16_t RenderComponent_type { 0 }; //extern fa que tot el que necessite numComponentes i tinga components coneix la variable

struct RenderComponent : Component {
   struct Data {
      uint16_t x{}, y{};
      uint16_t w{1}, h{1};
      Color c{WHITE};
   };
   Data data{};

   static Component::Type getType() noexcept {
      static auto id { ++numComponentes };
      return id;
   }

   explicit RenderComponent(Data d) : data{d} {}
   void update(Entity&) final;

};