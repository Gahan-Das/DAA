#include<stdio.h>
#define MAX 100

struct item{
    int idx;
    int profit;
    int weight;
};

void Sort();
void Knapsack();
void Swap();

void main(){
    struct item arr[MAX];
    int size, container_size;
    printf("\nEnter number of elements:");
    scanf("%d", &size);
    printf("\nEnter weight and profit for each item:");
    for(int i = 0; i < size; i++){
        arr[i].idx = i;
        scanf("%d", &arr[i].weight);
        scanf("%d", &arr[i].profit);
    }
    printf("\nEnter container size:");
    scanf("%d", &container_size);
    Knapsack(arr, size, container_size);
}

void Knapsack(struct item* arr, int size, int container_size){
    float final[MAX] = {0}, max_profit = 0;
    Sort(arr, size);
    for(int i = 0; i < size; i++){
        if(container_size == 0){
            break;
        }
        if(arr[i].weight <= container_size){
            container_size -= arr[i].weight;
            max_profit += arr[i].profit;
            final[arr[i].idx] = 1;
        }
        if(arr[i].weight > container_size){
            float fraction = ( 1.0 * container_size ) / arr[i].weight;
            container_size = 0;
            max_profit += fraction * arr[i].profit;
            final[arr[i].idx] = fraction;
            break;
        }
    }
    printf("\nMaximum Profit: %.2f\n", max_profit);
    for(int i = 0; i < size; i++){
        printf("%.2f\t", final[i]);
    }
}

void Sort(struct item* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j].weight > arr[j+1].weight){
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Swap(struct item* A, struct item* B){
    struct item temp = *A;
    *A = *B;
    *B = temp;
}
