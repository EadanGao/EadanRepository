#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int tri[n][n];
    memset(tri, 0, sizeof(tri));
    int num = 1;

    for(int i = 0; i < n; i++){
        int j = i, k = 0;
        while(j > -1){
            tri[j][k] = num++;
            j--, k++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++) printf("%d ", tri[i][j]);
        printf("\n");
    }

    return 0;
}