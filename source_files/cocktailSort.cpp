#include "sort.h"
#include "mainVar.h"

void cocktail_sort(){
    bool swapped;
    int st=0,en=N-1;
    do{
        swapped=false;
        for(int i=st;i<en;i++){
            renderArray(i,i+1);
            SDL_Delay(delay);
            if(arr[i]>arr[i+1]){
                std::swap(arr[i], arr[i+1]);
                swapped=true;
                renderArray(i+1,i);
                SDL_Delay(delay);
            }
        }
        en--;
        if(!swapped)
            break;
        
        swapped=false;
        for(int i=en-1;i>=st;i--){
            if(arr[i]>arr[i+1]){
                renderArray(i,i+1);
                SDL_Delay(delay);
                std::swap(arr[i], arr[i+1]);
                swapped=true;
                renderArray(i+1,i);
                SDL_Delay(delay);
            }
        }
        st++;
    }while(swapped);
    isSorted=true;
}