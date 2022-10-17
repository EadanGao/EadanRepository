#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

void swapstring(char *a, char *b){
    int m = max(strlen(a), strlen(b));
    for(int i = 0; i <= m; i++){
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char strs[n][105];
    for(int i = 0; i < n; i++) scanf("%s", strs[i]);

    for(int i  = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            // int l1 = strlen(strs[j]), l2 = strlen(strs[j + 1]);
            int minl = min(strlen(strs[j]), strlen(strs[j + 1]));
            for(int k = 0; k < minl; k++){
                if(strs[j][k] > strs[j + 1][k]){
                    swapstring(strs[j], strs[j + 1]);
                    break;
                }
                else if(strs[j][k] < strs[j + 1][k]) break;
                else if(k == minl - 1){
                    if(strlen(strs[j]) > strlen(strs[j + 1])) swapstring(strs[j], strs[j + 1]);
                }
            }
            
        }
    }

    // printf("\n");
    // swapstring(strs[0], strs[1]);
    for(int i = 0; i < n; i++) printf("%s\n", strs[i]);
    return 0;
}