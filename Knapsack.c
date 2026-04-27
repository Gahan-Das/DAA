#include<stdio.h>
#define MAX 100 

struct item{
    int idx;
    int weight;
    int profit;
};

void Insertion_Sort();
void Knapsack();
void Swap();

void main(){
    Knapsack();
}

void Knapsack(){
    int container_size, size, k = 0;
    float result[MAX] = {0}, max_profit = 0;
    struct item values[MAX];
    printf("\nEnter container size:");
    scanf("%d", &container_size);
    printf("\nEnter the number of items:");
    scanf("%d", &size);
    printf("\nEnter weight, profit for each item:");
    for (int i = 0; i < size; i++){
        values[i].idx = i;
        scanf("%d", &values[i].weight);
        scanf("%d", &values[i].profit);
    }
    
    Insertion_Sort(values, size);
    for (int i = 0; i < size; i++){
        printf("\n%d %d %d", values[i].idx, values[i].weight, values[i].profit);
    }
    for (int i = 0; i < size; i++){
        if(container_size == 0){
            break;
        }
        else{
            if(values[i].weight <= container_size){
                container_size -= values[i].weight;
                max_profit += values[i].profit;
                result[values[i].idx] = 1;
            }
            else{
                float fraction = ( 1.0 * container_size ) / values[i].weight;
                container_size = 0;
                max_profit += fraction * values[i].profit;
                result[values[i].idx] = fraction;
            }
        }
    }
    printf("\nMaximum Profit: %.2f\n", max_profit);
    for (int i = 0; i < size; i++){
        printf("%.2f\t", result[i]);
    }
}

void Insertion_Sort(struct item* values, int size){
    for (int i = 1; i < size ; i++){
        int y = i - 1, weight = values[i].weight, profit = values[i].profit, idx = values[i].idx;
        
        while(values[y].profit < profit && y >= 0){
            values[y+1].profit = values[y].profit;
            values[y+1].weight = values[y].weight;
            values[y+1].idx = values[y].idx;
            y -= 1;
        }
        values[y+1].weight = weight;
        values[y+1].profit = profit;
        values[y+1].idx = idx;
    }
}

void Swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
}