#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <string>

//Ctes
constexpr uint16_t SCR_WIDTH = 800; //objetos conocidos en tiempo de compilación
constexpr uint16_t SCR_HEIGHT = 600;
constexpr size_t MAX_ENTITIES = 100; //fer private
const char* GAME_NAME = "My Game";

 
struct Pixel {
   uint16_t x{}, y{};
};

// Dará acceso al array devolviendolo por referencia constante
struct EntityManager {
   EntityManager() {
      for(auto& p: pixeles_) {
         p.x = static_cast<uint16_t>(rand()) % SCR_WIDTH; //el casteo de veres en c++ es fa aixina //unsigned ssize_t
         p.y = static_cast<uint16_t>(rand()) % SCR_HEIGHT;
      }
   }
 
   std::array<Pixel, MAX_ENTITIES> const& getPixeles() const { return pixeles_; }
private:
   std::array<Pixel, MAX_ENTITIES> pixeles_{};
};
 
// Recibira como parámetro una referencia al EntityManager
// Le pedirá el array al entity manager y lo pintará
void render_system(EntityManager& EM) {
   BeginDrawing();
   for(auto& p: EM.getPixeles()) {
      DrawPixel(p.x, p.y, RED);
   }
   EndDrawing();
}
 
// Crear un EntityManager
// Pásarselo al RenderSystem
int main() {
   InitWindow(SCR_WIDTH, SCR_HEIGHT, GAME_NAME);
   EntityManager  EM{};
 
   while ( ! WindowShouldClose() ) {
      render_system(EM);
   }
 
   CloseWindow();
}