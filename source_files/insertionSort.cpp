#include "sort.h"
#include "mainVar.h"

void insertion_sort(){
    for(int i=1;i<N;i++){
        int key=arr[i];
        int j=i-1;
        renderArray(i);
        SDL_Delay(delay);
        while(j>=0&&arr[j]>key){
            renderArray(j+1,j);
            SDL_Delay(delay);
            std::swap(arr[j+1], arr[j]);
            renderArray(j,j+1);
            j--;
            SDL_Delay(delay);
        }
        arr[j+1]=key;
    }
    isSorted=true;
}