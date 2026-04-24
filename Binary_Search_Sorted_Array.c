#include<stdio.h>

int Binary_Search();

void main(){
    int size;
    printf("\nEnter number of elements you want to insert:");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the elements:");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    Binary_Search(arr, size);
}
int Binary_Search(int* arr, int size){
    int target;
    printf("\nEnter the value you want to search:");
    scanf("%d", &target);
    int l = 0;
    int r = size - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == target){
            printf("\nValue Found At %d", mid);
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