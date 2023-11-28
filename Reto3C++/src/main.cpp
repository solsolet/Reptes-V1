#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <span>
#include <optional>
 
///////////////////////////////////////////////////////
/// FICHERO: rendercomponent.cpp //
///////////////////////////////////////////////////////
 
constexpr uint16_t SCR_WIDTH  { 800 };
constexpr uint16_t SCR_HEIGHT { 600 };
 
struct RenderComponent{
   uint16_t x{}, y{};
   uint16_t w{1}, h{1};
   Color c{WHITE};
 
   void update() {
      DrawRectangle(x, y, w, h, c);
   }
};
struct PhysicsComponent{
   float x{}, y{};
   float vx{}, vy{};
 
   void update() {
      x += vx;
      y += vy;
   }
};
 
struct Entity {
   RenderComponent*  ren{};
   PhysicsComponent* phy{};
};
 
// Dará acceso al array devolviendolo por referencia constante
struct EntityManager {
   static constexpr std::size_t MAX_ENTITIES { 100 };
 
   Entity& newEntity() noexcept {
      assert(alive_ < MAX_ENTITIES);
      
      alive_ += 1;
      return entities_[alive_ - 1];
   }
 
   std::size_t freeEntities() const noexcept { return MAX_ENTITIES - alive_; }
 
   std::span<Entity const> getEntities() const { 
      return std::span{ entities_.begin(), alive_ }; 
   }
private:
   std::size_t alive_{};
   std::array<Entity, MAX_ENTITIES> entities_{};
};
 
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