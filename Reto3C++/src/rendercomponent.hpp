#pragma once
#include <cstdint>
#include <raylib.h>
#include <component.hpp>

struct RenderComponent : Component {
   struct Data {
      uint16_t x{}, y{};
      uint16_t w{1}, h{1};
      Color c{WHITE};
   };
   Data data{};

   constexpr static Component::Type getType() noexcept { return 2; }

   explicit RenderComponent(Data d) : data{d} {}
   void update(Entity&) final;
};