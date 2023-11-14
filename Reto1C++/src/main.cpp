#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <cassert>

//Ctes
constexpr uint16_t SCR_WIDTH = 800; //objetos conocidos en tiempo de compilación
constexpr uint16_t SCR_HEIGHT = 600;
const char* GAME_NAME = "My Game";

struct Entity {
   uint16_t x{}, y{};
};

// Dará acceso al array devolviendolo por referencia constante
struct EntityManager {
   static constexpr std::size_t MAX_ENTITIES { 100 }; //1 max_entities per a totos
   
   Entity& newEntity(){
      assert((alive_ < MAX_ENTITIES)&& "CUIDAO"); // codi de producció
      
      alive_ += 1; //llevar-se la mania del ++
      return entities_[alive_ - 1]; //entitat0
   }
      // freeEntities()
      //  
      // getEntities()????
 
   std::array<Entity, MAX_ENTITIES> const& getEntities() const { return entities_; }
private:
   std::size_t alive_ {}; //valor 0 per defecte
   std::array<Entity, MAX_ENTITIES> entities_{};
};
 
// Recibira como parámetro una referencia al EntityManager
// Le pedirá el array al entity manager y lo pintará
void render_system(EntityManager& EM) {
   BeginDrawing();
   for(auto& p: EM.getEntities()) {
      DrawPixel(p.x, p.y, RED);
   }
   EndDrawing();
}
 
// Crear un EntityManager
// Pásarselo al RenderSystem
int main() {
   InitWindow(SCR_WIDTH, SCR_HEIGHT, GAME_NAME);
   EntityManager EM{};

   for(auto i{0uz}; i<10; ++i){
      Entity& e = EM.newEntity(); //me refiero
      e.x = static_cast<uint16_t>(rand()) % SCR_WIDTH; //el casteo de veres en c++ es fa aixina //unsigned ssize_t
      e.y = static_cast<uint16_t>(rand()) % SCR_HEIGHT;
   }
 
   while ( ! WindowShouldClose() ) {
      render_system(EM);
   }
 
   CloseWindow();
}