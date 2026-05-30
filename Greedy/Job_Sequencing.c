#include<stdio.h>
#define MAX 100

struct job{
    int deadline;
    int profit;
    int idx;
};

void Sort();
void Swap();
void Job_Sequencing();

void main(){
    int size;
    struct job list[MAX];
    printf("\nEnter size of job list:");
    scanf("%d", &size);
    printf("\nEnter deadline and profit for each item:\n");
    for(int i = 0; i < size; i++){
        list[i].idx = i;
        scanf("%d", &list[i].deadline);
        scanf("%d", &list[i].profit);
    }
    Job_Sequencing(list, size);
}

void Job_Sequencing(struct job* arr, int size){
    int final[MAX] = {0}, max_profit = 0;
    Sort(arr, size);
    for(int i = 0; i < size; i++){
        int tmp = arr[i].deadline - 1;
        while(final[tmp] != 0 && tmp > -1){
            tmp = tmp - 1;
        }
        if(tmp != -1 && final[tmp] == 0){
            final[tmp] = arr[i].idx+1;
            max_profit += arr[i].profit;
        }
    }
    int max_deadline = 0;
    for(int i = 0; i < size; i++){
        if(max_deadline < arr[i].deadline){
            max_deadline = arr[i].deadline;
        }
    }
    printf("\nMaximum Profit: %d\n", max_profit);
    for(int i = 0; i < max_deadline; i++){
        printf("J%d\t",final[i]);
    }
}

void Sort(struct job* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j].profit < arr[j+1].profit){
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Swap(struct job* A, struct job* B){
    struct job temp = *A;
    *A = *B;
    *B = temp;
}