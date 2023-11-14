#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
 
struct Pixel {
   uint16_t x{}, y{};
};

// Dará acceso al array devolviendolo por referencia constante
struct EntityManager {
   EntityManager() {
      for(auto& p: pixeles_) {
         p.x = uint16_t(rand() % 800uz); //unsigned ssize_t
         p.y = uint16_t(rand() % 600uz);
      }
   }
 
   std::array<Pixel, 100> const& getPixeles() const { return pixeles_; }
private:
   std::array<Pixel, 100> pixeles_{};
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
   InitWindow(800, 600, "My Game");
   EntityManager  EM{};
 
   while ( ! WindowShouldClose() ) {
      render_system(EM);
   }
 
   CloseWindow();
}