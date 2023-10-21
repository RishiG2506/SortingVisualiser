#include "sort.h"
#include "mainVar.h"

void bubble_sort(){
    bool swapped=false;
    for(int i=0;i<N-1;i++){
        swapped=false;
        for(int j=0;j<N-1-i;j++){
            renderArray(j,j+1);
            SDL_Delay(delay);
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped=true;
                renderArray(j+1,j);
                SDL_Delay(delay);
            }
        }
        if(!swapped){
            break;
        }
    }
    isSorted=true;
}
