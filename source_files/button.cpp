#include "button.h"
#include <mainVar.h>

std::vector<Button*> Button::allButtons;


Button::Button(std::string name, int dest_x, int dest_y, int src_x, int src_y)
                : buttonName{name},
                drect{dest_x,dest_y,125,65},
                srect{src_x, src_y, 128, 69}
{
    allButtons.push_back(this);
}

void Button::updateButton(){
    if(isClicked){
        srect.x=754;
    }
    else if(SDL_HasIntersection(&drect, &mouse)){
        isSelected=true;
        srect.x=573;
    }
    else{
        isSelected=false;
        srect.x=391;
    }
}

void Button::renderButton(){
    SDL_RenderCopy(renderer, tex, &srect, &drect);
}