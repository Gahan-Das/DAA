#include<stdio.h>
#define MAX 100

struct Matrix{
    int idx;
    int row;
    int col;
};

void Matrix_Chain_Multiplication();
void Parentheses();

int main(){
    int size;
    struct Matrix List[MAX];
    printf("\nEnter number of matrices:");
    scanf("%d", &size);
    printf("\nEnter row and column value for each matrix:\n");
    for(int i = 0; i < size; i++){
        List[i].idx = i;
        scanf("%d", &List[i].row);
        scanf("%d", &List[i].col);
    }
    for(int i = 0; i < size-1; i++){
        if(List[i].col != List[i+1].row){
            printf("\nDimensions Mismatch");
            return 0;
        } 
    }
    Matrix_Chain_Multiplication(List, size);
    return 0;
}

void Matrix_Chain_Multiplication(struct Matrix* arr, int size){
    int multiply[MAX][MAX], parenthesis[MAX][MAX];
    for(int i = 0; i < size; i++){
        multiply[i][i] = 0;
    }

    int i = 0, j = 1, st = 2;
    while(st < size){
        if(j == size){
            i = 0;
            j = st;
            st += 1;
        }

        int min = multiply[i][i] + multiply[i+1][j] + arr[i].row * arr[i].col * arr[j].col ;
        parenthesis[i+1][j+1] = i+1;
        for(int k = i; k < j; k++){
            if (min > multiply[i][k] + multiply[k+1][j] + arr[i].row*arr[k].col*arr[j].col){
                min = multiply[i][k] + multiply[k+1][j] + arr[i].row*arr[k].col*arr[j].col;
                parenthesis[i+1][j+1] = k+1;
            }
        }
        multiply[i][j] = min;

        i += 1;
        j += 1;
    }

    printf("\nMinimum Number of Multiplication needed: %d\n", multiply[0][size-1]);
    Parentheses(parenthesis, 1, size);
}

void Parentheses(int arr[MAX][MAX], int l, int r){
    if(l == r){
        printf("%d", l);
    }
    else{
        printf("(");
        Parentheses(arr, l, arr[l][r]);
        Parentheses(arr, arr[l][r]+1, r);
        printf(")");
    }

}