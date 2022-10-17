#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%s", str);
    int N; 
    scanf("%d", &N);
    
    int length = strlen(str);
    double ratio = 0;
    int pointer = 0;

    for(int i = 0; i + N < length; i++){
        int cnt = 0;
        for(int j = i; j < i + N; j++){
            if(str[j] == 'G' || str[j] == 'C') cnt++;
        }
        if(ratio < (cnt + 0.0) / N){
            ratio = (cnt + 0.0) / N;
            pointer = i;
        }
    }
    for(int i = pointer; i < pointer + N; i++) printf("%c", str[i]);
    printf("\n");
    return 0;
}