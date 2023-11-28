#include "rendercomponent.hpp"
#include <raylib.h>
#include <entity.hpp>
#include <physicscomponent.hpp>

void
RenderComponent::update(Entity& e) {
   if(e.phy) {
      auto& p = *e.phy;
      x = static_cast<uint16_t>(p.x);
      y = static_cast<uint16_t>(p.y);
   }
      DrawRectangle(x, y, w, h, c);
}