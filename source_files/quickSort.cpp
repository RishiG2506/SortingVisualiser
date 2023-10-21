#include "sort.h"
#include "mainVar.h"

int partition(int lo, int hi){
    int pivot=arr[hi];
    renderArray(-1,-1,hi);
    SDL_Delay(delay);
    int i=lo;
    for(int j=lo;j<hi;j++){
        renderArray(i,j,hi);
        SDL_Delay(delay);
        if(arr[j]<pivot){
            std::swap(arr[i], arr[j]);
            i++;
            renderArray(j,i-1,hi);
            SDL_Delay(delay);
        }
    }
    renderArray(i,-1,hi);
    SDL_Delay(delay);
    std::swap(arr[i], arr[hi]);
    renderArray(hi,-1,i);
    SDL_Delay(delay);
    return i;
}
void quickSort(int lo, int hi){
    if(lo<hi){
        int p=partition(lo,hi);
        quickSort(lo, p-1);
        quickSort(p+1,hi);
    }
}

void quick_sort(){
    quickSort(0,N-1);
    isSorted=true;
}