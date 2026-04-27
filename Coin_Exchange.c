#include <stdio.h>
#define MAX 100

void Selection_Sort();
void Swap();
void Coin_Exchange();

void main(){
    int size, arr[MAX];
    printf("\nEnter the size of exchange values:");
    scanf("%d", &size);
    printf("\nEnter the exchange values:");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    Coin_Exchange(arr, size);
}

void Selection_Sort(int* arr, int size){
    for (int i = 0; i < size - 1; i++){
        int min_idx = arr[i];
        for (int j = i; j < size; j++){
            if(arr[j] < arr[min_idx]){
                Swap((arr + min_idx), (arr + j));
                min_idx = j;
            }
        }
    }
}

void Swap(int *A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

void Coin_Exchange(int* arr, int size){
    int target, values[size], k = 0;
    printf("\nEnter the target value:");
    scanf("%d", &target);
    Selection_Sort(arr, size);
    for (int i = size - 1; i >= 0; i--){
        if(arr[i] <= target){
            target -= arr[i];
            values[k] = arr[i];
            k++;
        }
        if(target == 0){
            break;
        }
    }
    if(target != 0){
        printf("\nGreedy Method Failed");
    }
    else{
        printf("\nThe values to reach target are:\n");
        for (int i = 0; i < k; i++){
            printf("%d\t", values[i]);
        }
    }
}