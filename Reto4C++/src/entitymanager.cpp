#include "entitymanager.hpp"
#include <cassert>

Entity& 
EntityManager::newEntity() noexcept {
   assert(alive_ < MAX_ENTITIES);
   
   alive_ += 1;
   return entities_[alive_ - 1];
}