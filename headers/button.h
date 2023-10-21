#ifndef BUTTON_H
#define BUTTON_H

#include<mainVar.h>
#include<vector>
#include<string>

class Button{
    public:
        static std::vector<Button*> allButtons;

        bool isSelected=false;
        bool isClicked=false;
        SDL_Rect srect,drect;
        std::string buttonName;
        
        Button(std::string name, int dest_x, int dest_y, int src_x, int src_y);
        void updateButton();
        void renderButton();
};
#endif