#include "rendercomponent.hpp"
#include <raylib.h>
#include <entity.hpp>
#include <physicscomponent.hpp>

void 
RenderComponent::update(Entity& e) {
   auto& d = data;
   auto PhyType = PhysicsComponent::getType();
   if ( e.components.contains(PhyType) ) {
      auto* c = e.components[PhyType];
      auto& p = static_cast<PhysicsComponent*>(c)->data;
      d.x = static_cast<uint16_t>(p.x);
      d.y = static_cast<uint16_t>(p.y);
   }
   DrawRectangle(d.x, d.y, d.w, d.h, d.c);
}