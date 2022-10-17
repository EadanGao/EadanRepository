#include <stdio.h>

int main() {
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    int matrixa[x][y], matrixb[y][z], matrixc[x][z];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            scanf("%d", &matrixa[i][j]);
        }
    }
    for(int i = 0; i < y; i++){
        for(int j = 0; j < z; j++){
            scanf("%d", &matrixb[i][j]);
        }
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            matrixc[i][j] = 0;
            for(int k = 0; k < y; k++){
                matrixc[i][j] += matrixa[i][k] * matrixb[k][j]; 
            }
        }
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            printf("%d ", matrixc[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}