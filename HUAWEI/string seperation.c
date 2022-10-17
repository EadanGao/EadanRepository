#include <stdio.h>
#include<string.h>

int main() {
    char str[105];
    char rst[13][9];
    scanf("%s", str);
    int length  = strlen(str);
    char * start = str;
    int i = 0;
    while(length >= 8){
        memcpy(rst[i++], start, 8);
        rst[i - 1][8] = '\0';
        start += 8;
        length -= 8;
    }

    if(length != 0){
        for(int j = length; j < 8; j++) start[j] = '0';
        memcpy(rst[i++], start, 8);
        rst[i - 1][8] = '\0';
    }
    for(int j = 0; j < i; j++) printf("%s\n", rst[j]);

    return 0;
}