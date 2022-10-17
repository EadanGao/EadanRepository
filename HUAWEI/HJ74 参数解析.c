#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    int cnt = 1, i = 0, quotation = 0;
    scanf("%[^\n]%*c", str);
    int length = strlen(str);
    while(i < length){
        if(str[i] == '"') quotation = ~quotation;
        if(str[i] == ' ' && !quotation){
            cnt++;
            str[i] = '\n';
        }
        if(quotation){
            str[i] = str[i + 1];
             if(str[i] == '"'){
                 str[i] = ' ', str[i + 1] = ' ';
                 quotation = ~quotation;
                 i++;
             }
        }
        i++;
    }
    printf("%d\n", cnt);
    printf("%s\n", str);
    return 0;
}