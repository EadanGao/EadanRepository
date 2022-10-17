#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int * weight = (int *) malloc(n * sizeof(int));
    int * number = (int *) malloc(n * sizeof(int));
    int maximum = 0;

    for(int i = 0; i < n; i++) scanf("%d", &weight[i]);
    for(int i = 0; i < n; i++) scanf("%d", &number[i]);

    for(int i = 0; i < n; i++) maximum += number[i] * weight[i];
    
    int *table = (int *) calloc(maximum + 1, sizeof(int));
    table[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < number[i]; j++){
            for(int k = maximum; k > -1; k--){
                if(table[k]) table[k + weight[i]] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < maximum + 1; i++) cnt += table[i];

    printf("%d\n", cnt);
    free(weight);
    free(number);
    free(table);


    return 0;
}