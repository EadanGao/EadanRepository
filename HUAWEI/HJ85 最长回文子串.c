#include <stdio.h>
#include <string.h>

int main() {
    char str[351];
    scanf("%s", str);
    int len = strlen(str); //printf("len = %d\n", len);
    int i = 0, substring = 0;
    while(i < len){
        int j = len - 1, cnt = 0;  
        while(i + cnt < j - cnt){
            while(str[i + cnt] == str[j - cnt] && (i + cnt < j - cnt)) cnt++;
            // printf("i %d j %d cnt %d\n", i, j, cnt);
            if(i + cnt >= j - cnt){
                cnt = j - i + 1;
                substring  = substring > cnt ? substring : cnt;
            }
            cnt = 0;
            j --;
        }
        i++;
    }
    printf("%d\n", substring);

    return 0;
}