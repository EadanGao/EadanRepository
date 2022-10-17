#include <stdio.h>

int v[4] = {0};

int dfs(int *a, int sum){
    if(sum == 24) return 1;
    for(int i = 0; i < 4; i++){
        if(!v[i]){
            v[i] = 1;
            if(dfs(a, sum + a[i]) || dfs(a, sum * a[i]) || dfs(a, sum - a[i]) || dfs(a, sum / a[i])) return 1;
            v[i] = 0;
        }
        
    }
    return 0;
}

int main() {
    int a[4];
    for(int i = 0; i < 4; i++) scanf("%d", &a[i]);
    int sum = a[0];
    v[0] = 1;

    if(dfs(a, sum)) printf("true\n");
    else printf("false\n");

    return 0;
}