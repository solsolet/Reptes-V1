#pragma once
#include <cstdint>

struct Entity;

struct Component {
   using Type = uint8_t;

   virtual void update(Entity&) = 0;
   virtual ~Component() = default;

protected:
   inline static Component::Type numComponentes { 0 }; //es global i no s'inclou en tots els fitxers
}; 