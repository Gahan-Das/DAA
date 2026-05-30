#include<stdio.h>
#define MAX 100

struct activity{
    int st;
    int ft;
    int idx;
};

void Activity_Selection();
void Sort();
void Swap();

void main(){
    struct activity list[MAX];
    int size;
    printf("\nEnter size of activities:");
    scanf("%d", &size);
    printf("\nEnter starting and finishing time for each activity:\n");
    for(int i = 0; i < size; i++){
        list[i].idx = i;
        scanf("%d", &list[i].st);
        scanf("%d", &list[i].ft);
    }
    Activity_Selection(list, size);
}

void Activity_Selection(struct activity* arr, int size){
    int final[MAX] = {0}, k = 0, last_ft = 0;
    Sort(arr, size);
    for(int i = 0; i < size; i++){
        if(arr[i].st >= last_ft){
            final[k] = arr[i].idx+1;
            last_ft = arr[i].ft;
            k = k + 1;
        }
    }
    printf("\nThe selected activities are:\n");
    for(int i = 0; i < k; i++){
        printf("A%d\t", final[i]);
    }
}

void Sort(struct activity* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j].ft > arr[j+1].ft){
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Swap(struct activity* A, struct activity* B){
    struct activity temp = *A;
    *A = *B;
    *B = temp;
}