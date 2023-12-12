#include "lifecomponent.hpp"
#include <entity.hpp>

void 
LifeComponent::update(Entity& e) {
   if ( data.life > 0 ) {
      data.life -= 1;
      if ( data.life == 0 ) {
         e.alive = false;
      }
   }
}