#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int height[n];
    for(int i = 0; i < n; i++) scanf("%d", &height[i]);
    int max = 1;
    int table[201] = {0};
    table[0] = 1;

    for(int i = 1; i < n; i++){
        int val = 0;
        for(int j = 0; j < i; j++){
            if(height[j] < height[i]) val = val > table[j] ? val : table[j];
        }
        table[i] = val + 1;
        max = max > table[i] ? max : table[i];
        //
    }
    printf("%d\n", max);
    return 0;
}