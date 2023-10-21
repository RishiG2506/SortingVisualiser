#include "sort.h"
#include "mainVar.h"

void mergeArrays(int st, int mid, int en){
    int merge_size=en-st+1;
    int *temp_array=new int[merge_size];
    int i=st, j=mid+1, k=0;
    while(i<=mid&&j<=en){
        renderArray(i,j);
        SDL_Delay(delay);
        if(arr[i]<=arr[j]){
            temp_array[k++]=arr[i++];
        }
        else{
            temp_array[k++]=arr[j++];
        }
    }
    while(i<=mid){
        renderArray(i);
        SDL_Delay(delay);
        temp_array[k++]=arr[i++];
    }
    while(j<=en){
        renderArray(j);
        SDL_Delay(delay);
        temp_array[k++]=arr[j++];
    }
    int index=0;
    for(i=st; i<=en;i++){
        arr[i]=temp_array[index++];
        renderArray(-1,-1,i);
        SDL_Delay(delay);
    }
    delete[] temp_array;
}

void mergeSort(int st, int en){
    if(st<en){
        int mid=(st+en)/2;
        mergeSort(st, mid);
        mergeSort(mid+1, en);
        mergeArrays(st,mid,en);
    }
}

void merge_sort(){
    mergeSort(0, N-1);
    isSorted=true;
}
