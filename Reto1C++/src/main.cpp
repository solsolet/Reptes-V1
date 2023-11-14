#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <string>

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
   
   EntityManager() {
      /* for(auto& p: entities_) {
         p.x = static_cast<uint16_t>(rand()) % SCR_WIDTH; //el casteo de veres en c++ es fa aixina //unsigned ssize_t
         p.y = static_cast<uint16_t>(rand()) % SCR_HEIGHT;
      } */
      // newEntity();
      // ??? > 100
      //   #include <cassert>
      //   assert() // noseque que hace pum
      // freeEntities()
      //  
      // getEntities()????
   }
 
   std::array<Entity, MAX_ENTITIES> const& getEntities() const { return entities_; }
private:
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

   //for() 10 entitats
   //EM.newEntity();
 
   while ( ! WindowShouldClose() ) {
      render_system(EM);
   }
 
   CloseWindow();
}