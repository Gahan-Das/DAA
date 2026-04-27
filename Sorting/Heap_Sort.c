#include<stdio.h>

void Build_Max_Heap();
void Heapify();
void Heap_Sort();
void Swap();

void main(){
    int size;
    printf("\nEnter the number of elements you want to insert:");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the elements:");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nElements before Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    Heap_Sort(arr, size);
    printf("\nElements after Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

void Heap_Sort(int* arr, int size){
    Build_Max_Heap(arr, size);
    for (int i = size-1; i >= 1; i--)
    {
        Swap((arr), (arr + i));
        Heapify(arr, 0, i);
    }
}

void Build_Max_Heap(int* arr, int size){
    for (int i = size / 2; i >= 0; i--){
        Heapify(arr, i, size);
    }
}

void Heapify(int* arr, int idx, int size){
    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;
    if(left_child < size || right_child < size){
        if(arr[idx] < arr[left_child] || arr[idx] < arr[right_child]){
            int max_idx = arr[left_child] > arr[right_child] ? left_child : right_child;
            Swap((arr + idx), (arr + max_idx));
            Heapify(arr, max_idx, size);
        }
    }
}

void Swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}
