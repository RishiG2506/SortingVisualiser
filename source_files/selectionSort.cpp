#include "sort.h"
#include "mainVar.h"

void selection_sort(){
    for(int i=0;i<N-1;i++){
        int min_index=i;
        renderArray(-1,-1,min_index);
        SDL_Delay(delay);
        for(int j=i+1;j<N;j++){
            renderArray(min_index, j, i);
            SDL_Delay(delay);
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        renderArray(min_index, -1, i);
        SDL_Delay(delay);
        if(min_index!=i){
            std::swap(arr[i], arr[min_index]);
            renderArray(i, -1, min_index);
            SDL_Delay(delay);            
        }
    }
    isSorted=true;
}