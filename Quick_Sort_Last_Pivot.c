#include<stdio.h>

void Quick_Sort();
int Partition();
void Swap();

void main(){
    int size;
    printf("\nEnter the number of elements you want to insert:");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the elements:");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nElements before Sorting:\n");
    for(int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    Quick_Sort(arr, 0, size-1);
    printf("\nElements after Sorting:\n");
    for(int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

void Quick_Sort(int* arr, int left, int right){
    if(left < right){
        int mid = Partition(arr, left, right);
        Quick_Sort(arr, left, mid-1);
        Quick_Sort(arr, mid+1, right);
    }
}

int Partition(int* arr, int left, int right){
    int pivot = arr[right];
    int i = left, j = right-1;
    while(i < j){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            Swap((arr + i), (arr + j));
        }
        else{
            Swap((arr + i), (arr + right));
        }
    }
    return i;
}

void Swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}