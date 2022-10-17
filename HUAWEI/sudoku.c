#include <stdio.h>

int sudoku[10][10];

int nextSpace(int *i, int *j){
    for(int k = 1; k < 10; k++){
        for(int l = 1; l < 10; l++){
            if(!sudoku[k][l]){
                *i = k;
                *j = l;
                return 1;
            }
        }
    }
    return 0;
}

int islegal(int i, int j, int val){
    for(int k = 1; k < 10; k++){
        if(sudoku[i][k] == val) return 0;
    }

    for(int k = 1; k < 10; k++){
        if(sudoku[k][j] == val) return 0;
    }
    int x = (i - 1) / 3 * 3 + 3;
    int y = (j - 1) / 3 * 3 + 3;
    for(int k = x - 2; k <= x; k++){
        for(int l = y - 2; l <= y; l++){
            if(sudoku[k][l] == val) return 0;
        }
    }
    return 1;
    
}

int fillspace(int i, int j){
    int complete = nextSpace(&i, &j);
    if(!complete) return 1;

    int next = 0;

    for(int k = 1; k < 10; k++){
        if(islegal(i, j, k)){
            sudoku[i][j] = k;
            next = fillspace(i, j);
            if(next) return 1;

        }
    }
    sudoku[i][j] = 0;
    return 0;
}


int main(){
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++) scanf("%d", &sudoku[i][j]);
    }

    fillspace(0, 0);
    

    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

