#include<stdio.h>

void Max_Min();

void main()
{
    int size, max, min;
    printf("\nEnter the number of elements you want to insert:");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the elements:");
    for(int i = 0; i <size; i++){
        scanf("%d", &arr[i]);
    }

    Max_Min(arr, 0, size-1, &max, &min);
    printf("\nMinimum Value is: %d", min);
    printf("\nMaximum Value is: %d", max);
}

void Max_Min(int* arr, int left, int right, int* max, int* min){
    if(left == right){
        *max = *min = arr[left];
    }
    else if(left + 1 == right){
        if(arr[left] < arr[right]){
            *min = arr[left];
            *max = arr[right];
        }
        else{
            *min = arr[right];
            *max = arr[left];
        }
    }
    else{
        int mid = (left + right) / 2;
        int min1, max1, min2, max2;
        Max_Min(arr, left, mid, &max1, &min1);
        Max_Min(arr, mid+1, right, &max2, &min2);
        if(min1 < min2){
            *min = min1;
        }
        else{
            *min = min2;
        }
        if(max1 > max2){
            *max = max1;
        }
        else{
            *max = max2;
        }
    }
}