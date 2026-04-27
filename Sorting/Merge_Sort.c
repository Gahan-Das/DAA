#include<stdio.h>

void Merge_Sort();
void Merge();

void main(){
    int size;
    printf("\nEnter the number of elements you want to insert:");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the elements:");
    for (int i = 0; i < size; i ++){
        scanf("%d", &arr[i]);
    }
    printf("\nElements before Sorting:\n");
    for (int i = 0; i < size; i ++){
        printf("%d\t", arr[i]);
    }
    Merge_Sort(arr, 0, size-1);
    printf("\nElements after Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

void Merge_Sort(int* arr, int left, int right){
    if(right  - left > 1){
        int mid = (left + right) / 2;
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void Merge(int* arr, int left, int mid, int right){
    int size = right - left;
    int temp[size];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = left, j = 0; i <= right; i++, j++){
        arr[i] = temp[j];
    }
}
