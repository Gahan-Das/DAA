#include<stdio.h>

void Bubble_Sort();
void Swap();
int Binary_Search();

void main(){
    int size;
    printf("\nEnter number of elements you want to insert:");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the elements:");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    Bubble_Sort(arr, size);
    Binary_Search(arr, size);
}

void Bubble_Sort(int* arr, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                Swap((arr+j), (arr+j+1));
            }
        }
    }
}
void Swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}
int Binary_Search(int* arr, int size){
    int target;
    printf("\nEnter value to search:");
    scanf("%d", &target);
    int l = 0;
    int r = size - 1;
    while( l <= r ){
        int mid = (l + r) / 2;
        if(arr[mid] == target){
            printf("\nValue Found");
            return 1;
        }
        else if(arr[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    printf("\nValue Not Found");
    return 0;
}