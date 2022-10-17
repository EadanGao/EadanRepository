#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int main() {
    int N;
    scanf("%d", &N);
    int * height = NULL;
    height =  (int *) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) scanf("%d", &height[i]);

    int * lline = (int *) calloc(N, sizeof(int));
    int * rline = (int *) calloc(N, sizeof(int));

    for(int i = 0; i < N; i++) lline[i]++,rline[i]++;

    // left
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(height[j] < height[i] && lline[i] < lline[j] + 1) lline[i] = lline[j] + 1;
        }
    }

    // right
    for(int i = N - 2; i > -1; i--){
        for(int j = N - 1; j > i; j--){
            if(height[j] < height[i] && rline[i] < rline[j] + 1) rline[i] = rline[j] + 1;
        }
    }

    for(int i = 0; i < N; i++){
        lline[i] += (rline[i] - 1);
        lline[0] = max(lline[0], lline[i]);
    }

    printf("%d\n", N - lline[0]);

    // free(height);
    // free(lline);
    // free(rline);
    
    return 0;
}