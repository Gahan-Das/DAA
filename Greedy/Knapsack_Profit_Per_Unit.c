#include<stdio.h>
#define MAX 100


struct item{
    int idx;
    int profit;
    int weight;
};

void Knapsack();
void Sort();
void Swap();

void main(){
    struct item arr[MAX];
    int size, container_size;
    printf("\nEnter number of elements:");
    scanf("%d", &size);
    printf("\nEnter weight and profit for each element:");
    for(int i = 0; i < size; i++){
        arr[i].idx = i;
        scanf("%d", &arr[i].weight);
        scanf("%d", &arr[i].profit);
    }
    printf("\nEnter size of container:");
    scanf("%d", &container_size);
    Knapsack(arr, size, container_size);
}

void Knapsack(struct item* arr, int size, int container_size){
    float max_profit = 0, result[MAX] = {0};
    Sort(arr, size);
    for(int i = 0; i < size; i++){
        if(container_size == 0){
            break;
        }
        if(arr[i].weight <= container_size){
            container_size -= arr[i].weight;
            max_profit += arr[i].profit;
            result[arr[i].idx] = 1;
        }
        else{
            float fraction = (1.0 * container_size) / arr[i].weight;
            container_size = 0;
            max_profit += fraction * arr[i].profit;
            result[arr[i].idx] = fraction;
            break;
        }
    }
    printf("\nMaximum Profit: %.2f\n", max_profit);
    for(int i = 0; i < size; i++){
        printf("%.2f\t", result[i]);
    }
}

void Sort(struct item* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if((1.0 * arr[j]. profit ) / arr[j].weight < (1.0 * arr[j+1].profit ) / arr[j+1].weight){
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