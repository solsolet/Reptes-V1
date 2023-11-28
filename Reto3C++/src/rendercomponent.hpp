#pragma once
#include <cstdint>
#include <raylib.h>

struct RenderComponent{
   uint16_t x{}, y{};
   uint16_t w{1}, h{1};
   Color c{WHITE};
 
   void update() {
      
   }
};