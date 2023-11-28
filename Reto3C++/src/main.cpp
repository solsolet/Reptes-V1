#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <cassert>

#include <physicscomponent.hpp>
#include <rendercomponent.hpp>
#include <entitymanager.hpp>
 
constexpr uint16_t SCR_WIDTH  { 800 };
constexpr uint16_t SCR_HEIGHT { 600 };
 
void update_entities(EntityManager& EM) {
   for( auto& e : EM.getEntities() ) {
      if ( e.phy ) { e.phy->update(); }
   }
}
 
void render_system(EntityManager& EM) {
   BeginDrawing();
 
   for( auto& e : EM.getEntities() ) {
      if ( e.ren ) { e.ren->update(); }
   }
 
   EndDrawing();
}
 
int main() {
   InitWindow(SCR_WIDTH, SCR_HEIGHT, "My Game");
   EntityManager  EM{};
   PhysicsComponent p{  .x=1.f, .y=2.f, .vy=-1.f },
                    p2{ .vx=2.f };
   RenderComponent  r{ .x=100, .y=2, .w=50, .h=25 };
   RenderComponent  r2 { .w=20, .h=20 };
               
   {
      auto& e = EM.newEntity();
      e.phy = &p;
      e.ren = &r;
   }
   {
      auto& e = EM.newEntity();
      e.ren = &r2;
   }
   {
      auto& e = EM.newEntity();
      e.phy = &p2;
   }
   EM.newEntity();
   
   while ( ! WindowShouldClose() ) {
      update_entities(EM);
      render_system(EM);
   }
 
   CloseWindow();
}