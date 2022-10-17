#include <stdio.h>
#include <string.h>


int main() {
    char str[201];
    while(~scanf("%s", str)){
        char numbers[100];
        int max = 0, offset = 0, i = 0, pointer = 0;;
        int len = strlen(str);

        while(i < len){
            offset = 0;
            while((str[i] > '9' || str[i] < '0') && i < len) i++;
            while(str[i + offset] <= '9' && str[i + offset] >= '0' && i + offset < len) offset++;
            if(offset > max){
                max = offset;
                for(int k = 0; k < offset; k++) numbers[k] = str[i + k];
                pointer = offset;
            }
            else if(offset == max){
                for(int k = 0; k < offset; k++) numbers[k + pointer] = str[i + k];
                pointer += offset;
            }
            i += offset;
        }

        for(int j = 0; j < pointer; j++) printf("%c", numbers[j]);
        printf(",%d\n", max);
    }
    
    return 0;
}