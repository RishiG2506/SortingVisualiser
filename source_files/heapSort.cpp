#include "sort.h"
#include "mainVar.h"

void heapify(int index, int heap_size){
    int largest=index;
    //Children of node
    int left=2*index+1;
    int right=left+1;

    if(left<heap_size){
        renderArray(-1,left, largest);
        SDL_Delay(delay);

        if(arr[left]>arr[largest]){
            largest=left;
            renderArray(-1,-1,largest);
            SDL_Delay(delay);
        }
    }
    if(right<heap_size){
        renderArray(index, right, largest);
        SDL_Delay(delay);

        if(arr[right]>arr[largest]){
            largest=right;
            renderArray(index, -1, largest);
            SDL_Delay(delay);
        }
    }
    if(largest!=index){
        renderArray(index,-1,largest);
        SDL_Delay(delay);

        std::swap(arr[index], arr[largest]);

        renderArray(largest,-1,index);
        SDL_Delay(delay);

        heapify(largest, heap_size);
    }
}
void heap_sort(){
    int heap_size=N;
    //Building max-heap
    for(int i=N/2-1;i>=0;i--){
        heapify(i, N);
    }


    //Pop Max-element and rebuilding heap
    for(int i=N-1;i>=0;i--){
        renderArray(0,-1,i);
        SDL_Delay(delay);

        std::swap(arr[0], arr[i]);

        renderArray(i,-1,0);
        SDL_Delay(delay);

        heap_size--;
        heapify(0, heap_size);
    }
    isSorted=true;
}