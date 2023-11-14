#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <string>

//Cte
uint16_t SCREEN_HEIGHT = 600;
uint16_t SCREEN_WEIGHT = 800;
const size_t TAM_ARRAY = 100;
const char* GAME_NAME = "My Game";

 
struct Pixel {
   uint16_t x{}, y{};
};

// Dará acceso al array devolviendolo por referencia constante
struct EntityManager {
   EntityManager() {
      for(auto& p: pixeles_) {
         p.x = static_cast<uint16_t>(rand()) % SCREEN_WEIGHT; //el casteo de veres en c++ es fa aixina //unsigned ssize_t
         p.y = static_cast<uint16_t>(rand()) % SCREEN_HEIGHT;
      }
   }
 
   std::array<Pixel, TAM_ARRAY> const& getPixeles() const { return pixeles_; }
private:
   std::array<Pixel, TAM_ARRAY> pixeles_{};
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
   InitWindow(SCREEN_WEIGHT, SCREEN_HEIGHT, GAME_NAME);
   EntityManager  EM{};
 
   while ( ! WindowShouldClose() ) {
      render_system(EM);
   }
 
   CloseWindow();
}