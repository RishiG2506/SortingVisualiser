#include "mainVar.h"
#include "sort.h"
#include "button.h"
using namespace std;

//SDL Renderer and SDL Window
SDL_Renderer *renderer=nullptr;
SDL_Window *window=nullptr;

//Window dimensions
const int WINDOW_HEIGHT=720;
const int WINDOW_WIDTH=1200;

//Frame Delay
const int delay=30;

//Array Vector
const int N=50;
const int maxValue=100;
const int minValue=5;
int arr[N];
const double scalingFactor=((double)WINDOW_HEIGHT * 0.65)/(100);

//Rectangle width
const int rect_width=WINDOW_WIDTH/N;
const int border_width=1;

//Bool Value for Completed Sort
bool isSorted=false;

//Texture Var to render GUI features
SDL_Texture* tex;

//Mouse
SDL_Rect mouse;

//Window title rect
SDL_Rect title_dest;
SDL_Rect title_src;

void initArray(){
    srand(time(NULL));
    for(int i=0;i<N;i++){
        arr[i]=(rand()%(maxValue-minValue+1)+minValue);
    }
}


void loadButtons(){

    int button_depth=120;
    Button* sSort=new Button("Selection", 25, button_depth, 391, 45);
    Button* bSort=new Button("Bubble", 160, button_depth, 391, 134);
    Button* mSort=new Button("Merge", 295, button_depth, 391, 222);
    Button* qSort=new Button("Quick", 430, button_depth, 391, 310);
    Button* hSort=new Button("Heap", 565, button_depth, 391, 399);
    Button* cSort=new Button("Cocktail", 700, button_depth, 391, 487);
    Button* iSort=new Button("Insertion", 835, button_depth, 391, 575);
    Button* newArray=new Button("New", 1050, button_depth, 391, 663);
}


int initialise(){
    SDL_Init(SDL_INIT_VIDEO);
    window=SDL_CreateWindow("Sorting Algorithms Visualiser", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window){
        std::cout<<"Window could not be created! Exiting..."<<std::endl;
        return 0;
    }
    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED||SDL_RENDERER_PRESENTVSYNC);
    if(renderer==NULL){
        std::cout<<"Renderer could not be initialised! Exiting..."<<std::endl;
        return 0;
    }

    //Mouse rectangle which follows mouse pointer
    mouse={0,0,1,1};

    //Texture variable initialisation
    tex=IMG_LoadTexture(renderer, "gui_elements.png");
    

    //Initialisation of Buttons
    loadButtons();

    //Window Title
    title_src={391,774,891,58};
    title_dest={600-384,30,768,50};
    return 1;
}


void renderArray(int key, int swapped, int pivot){
    //Background
    SDL_SetRenderDrawColor(renderer, 33, 36, 41, 255);
    SDL_RenderClear(renderer);

    //Rendering all buttons
    for(Button* button: Button::allButtons){
        button->renderButton();
    }

    
    for(int i=0;i<N;i++){
        //Push any instructions during sorting to Event Queue
        SDL_PumpEvents();

        int height=scalingFactor*arr[i];

        SDL_RenderCopy(renderer, tex, &title_src, &title_dest);

        //Rendering the black border for each array element
        SDL_Rect border{i*rect_width, WINDOW_HEIGHT-height, rect_width, height};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &border);

        //Element Rectangle
        SDL_Rect rect{i*rect_width+border_width, WINDOW_HEIGHT-height+border_width, rect_width-2*(border_width), height-2*(border_width)};

        if(isSorted){
            SDL_SetRenderDrawColor(renderer, 40, 234, 21, 255);
            SDL_RenderFillRect(renderer, &rect);
            continue;
        }
        if(i==key){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        else if(i==swapped){
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        else if(i==pivot){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        else{
            SDL_SetRenderDrawColor(renderer, 30,225,223, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    SDL_RenderPresent(renderer);
}


void mainLoop(){
    bool app_running=true;
    while(app_running){

        //Update status of all the buttons
        for(Button* button: Button::allButtons){
            button->updateButton();
        }
        SDL_Event event;

        //Load mouse pointer coordinates to the mouse rectangle each frame
        SDL_GetMouseState(&mouse.x,&mouse.y);
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                app_running=false;
                break;
            }
            else if(event.type==SDL_MOUSEBUTTONDOWN){
                if(Button::allButtons[0]->isSelected){
                    isSorted=false;
                    Button::allButtons[0]->isClicked=true;
                    Button::allButtons[0]->updateButton();
                    selection_sort();
                    Button::allButtons[0]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[1]->isSelected){
                    isSorted=false;
                    Button::allButtons[1]->isClicked=true;
                    Button::allButtons[1]->updateButton();
                    bubble_sort();
                    Button::allButtons[1]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[2]->isSelected){
                    isSorted=false;
                    Button::allButtons[2]->isClicked=true;
                    Button::allButtons[2]->updateButton();
                    merge_sort();
                    Button::allButtons[2]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[3]->isSelected){
                    isSorted=false;
                    Button::allButtons[3]->isClicked=true;
                    Button::allButtons[3]->updateButton();
                    quick_sort();
                    Button::allButtons[3]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[4]->isSelected){
                    isSorted=false;
                    Button::allButtons[4]->isClicked=true;
                    Button::allButtons[4]->updateButton();
                    heap_sort();
                    Button::allButtons[4]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[5]->isSelected){
                    isSorted=false;
                    Button::allButtons[5]->isClicked=true;
                    Button::allButtons[5]->updateButton();
                    cocktail_sort();
                    Button::allButtons[5]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[6]->isSelected){
                    isSorted=false;
                    Button::allButtons[6]->isClicked=true;
                    Button::allButtons[6]->updateButton();
                    insertion_sort();
                    Button::allButtons[6]->isClicked=false;
                    break;
                }
                else if(Button::allButtons[7]->isSelected){
                    isSorted=false;
                    Button::allButtons[7]->isClicked=true;
                    Button::allButtons[7]->updateButton();
                    initArray();
                    Button::allButtons[7]->isClicked=false;
                    break;
                }

            }
        }
        renderArray();
    }
}

int main(int argv, char** args){
    std::cout<<"--------------------Sorting Algorithms Visualiser--------------------"<<std::endl;
    int init=initialise();
    if(!init) return 0;
    initArray();
    mainLoop();    

}

