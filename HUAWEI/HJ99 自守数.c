#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i <= n; i++){
        int ii = i, square = i * i;
        while(ii > 0){
            int temp = ii % 10;
            int temp2 = square % 10;
            if(temp == temp2){
                ii /= 10;
                square /= 10;
                continue;
            }
            else{
                cnt++;
                break;
            } 
        }
    }
    printf("%d\n", n + 1 - cnt);
    
    return 0;
}