#include "lifecomponent.hpp"

struct Entity;

void 
LifeComponent::update(Entity&) {
    if (data.l > 0){
        data.l -= 1;
        if(data.l == 0){
            e.alive = false;
        }
    }
}