#ifndef RENDERCOMPONENT_HPP
#define RENDERCOMPONENT_HPP

struct RenderComponent{
   uint16_t x{}, y{};
   uint16_t w{1}, h{1};
   Color c{WHITE};
 
   void update() {
      DrawRectangle(x, y, w, h, c);
   }
};

#endif