#include <cstdlib>
#include <rendercomponent.hpp>
#include <lifecomponent.hpp>
#include <physicscomponent.hpp>
#include <entitymanager.hpp>
#include <memviewer.hpp>

constexpr uint16_t SCR_WIDTH  { 800 };
constexpr uint16_t SCR_HEIGHT { 600 };

void update_entities(EntityManager& EM) {
   for( auto& e : EM.getEntities() ) {
      e.update();
   }
}

void render_system(EntityManager& EM) {
   BeginDrawing();
   ClearBackground(BLACK);

   for( auto& e : EM.getEntities() ) {
      auto* renc = e.getComponent(RenderComponent({}));
      if ( renc ) { renc->update(e); }
   }

   EndDrawing();
}

int main() {
   InitWindow(SCR_WIDTH, SCR_HEIGHT, "My Game");
   EntityManager  EM{};
   PhysicsComponent p({ .x=1.f, .y=2.f, .vy=0.01f }),
                     p2({ .vx=2.f });
   RenderComponent  r({ .x=100, .y=2, .w=50, .h=25 });
   RenderComponent r2({ .w=20, .h=20 });
   LifeComponent    l({ .life=30 });

   MemViewer MV{r};
   MV.print();

   {
      auto& e = EM.newEntity();
      e.addComponent(r);
      e.addComponent(p);
      //e.addComponent(l);
      auto const& ec = e;
      //auto& c = e.getComponent(LifeComponent{});
      //auto const& cc = ec.getComponent(LifeComponent{});
   }
   {
      auto& e = EM.newEntity();
      e.addComponent(r2);
   }
   {
      auto& e = EM.newEntity();
      e.addComponent(p2);
   }
   EM.newEntity();
   
   while ( ! WindowShouldClose() ) {
      update_entities(EM);
      render_system(EM);
   }

   CloseWindow();
}