#include<stdio.h>

void main(){
    int size;
    printf("\nEnter number of elements you want to insert:");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the elements:");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
        }
        else if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("\nMinimum: %d \nMaximum: %d", min, max);
}