#include <stdio.h>
#include <string.h>

int main() {
    char a[301], b[301];
    scanf("%s%s", a, b);
    if(strlen(a) > strlen(b)){
        char temp[301];
        memcpy(temp, a, sizeof(a));
        memcpy(a, b, sizeof(b));
        memcpy(b, temp, sizeof(temp));
    }
    int lena = strlen(a), lenb = strlen(b);
    int rst = 0, pointer = 0;
    for(int i = 0; i < lena; i++){
        for(int j = 0; j < lenb; j++){
            int cnt = 0;
            while(a[i + cnt] == b[j + cnt] && i + cnt < lena) cnt++;
            if(cnt > rst){
                pointer = i;
                rst = cnt;
            }
        }
    }

    for(int i = pointer; i < pointer + rst; i++) printf("%c", a[i]);
    printf("\n");

    return 0;
}