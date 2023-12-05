#include <cstdlib>
#include <rendercomponent.hpp>
#include <physicscomponent.hpp>
#include <entitymanager.hpp>

constexpr uint16_t SCR_WIDTH  { 800 };
constexpr uint16_t SCR_HEIGHT { 600 };

void update_entities(EntityManager& EM) {
/*
   for( auto& e : EM.getEntities() ) {
      if ( e.phy  ) { e.phy->update(e); }
      if ( e.life ) { e.life->update(e); }
      if ( e.col  ) { e.col->update(e); }
      if ( e.pre  ) { e.pre->update(e); }
   }
*/  
   for( auto& e : EM.getEntities() ) {
      //for( auto& [_, c] : e.components ) {
      //   c->update(e);
      //}
      auto* phyc = e.getComponent(PhysicsComponent{}); //mètode tag dispatching
      if( phyc )
         phyc->update(e);
   }

}

void render_system(EntityManager& EM) {
   BeginDrawing();
   ClearBackground(BLACK);

   for( auto& e : EM.getEntities() ) {
      auto* renc = e.getComponent(RenderComponent({})); //quidra a un rc amb dades per defecte
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

//MemViewer MV{r};
               
   {
      auto& e = EM.newEntity();
      //e.ren = &r;
      //e.components[PhysicsComponent::getType()] = &p;
      e.addComponent(r);
      e.addComponent(p);
   }
   {
      auto& e = EM.newEntity();
      //e.ren = &r2;
      e.getComponent(r);
   }
   {
      auto& e = EM.newEntity();
      //e.phy = &p2;
      e.components[PhysicsComponent::getType()] = &p2;
   }
   EM.newEntity();
   
   while ( ! WindowShouldClose() ) {
      update_entities(EM);
      render_system(EM);
   }

   CloseWindow();
}