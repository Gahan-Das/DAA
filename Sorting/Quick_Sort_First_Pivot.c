#include<stdio.h>

int Quick_Sort();
void Swap();

void main(){
    int size;
    printf("\nEnter the numbe rof elements you want to insert:");
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
    Quick_Sort(arr, 0, size-1);
    printf("\nElements after Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

void Swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Quick_Sort(int* arr, int left, int right){
    if(right - left <= 1){
        return 0;
    }
    int pivot = arr[left];
    int i = left+1, j = right;
    while(i < j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            Swap((arr + i), (arr + j));
        }
        else{
            Swap((arr + left), (arr + i - 1));
        }
    }
    
    Quick_Sort(arr, left, i - 1);
    Quick_Sort(arr, i+1, right);
}
