#include <raylib.h>
#include <array>
#include <cstdint>
#include <cstdlib>
 
struct Pixel {
   uint16_t x{}, y{};
};
 
// Contendrá el array de 100 píxeles
// Dará acceso al array devolviendolo por referencia constante
struct EntityManager {
   // TODO
   std::array<Pixel, 100> pixeles;
};
 
// Recibira como parámetro una referencia al EntityManager
// Le pedirá el array al entity manager y lo pintará
void render_system(EntityManager pix) { 
   BeginDrawing();
   for(auto& p: pix.pixeles) { DrawPixel(pix.pixeles.x, pix.pixeles.y, RED); }
   EndDrawing();
}
 
// Crear un EntityManager
// Pásarselo al RenderSystem
int main() {
   InitWindow(800, 600, "My Game");

   EntityManager entityMan;

   for(auto& p: entityMan.pixeles) {
      p.x = rand() % 800;
      p.y = rand() % 600;
   }
 
   while ( ! WindowShouldClose() ) {
      render_system(entityMan);
   }
 
   CloseWindow();
}