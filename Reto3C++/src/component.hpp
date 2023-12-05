#pragma once
#include <cstdint>

struct Entity;

struct Component {
   using Type = uint8_t;

   virtual void update(Entity&) = 0;
   virtual ~Component() = default;
}; 