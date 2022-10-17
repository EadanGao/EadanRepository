#include <stdio.h>
#include <string.h>

int main() {
    char sstr[201], lstr[201];
    while(scanf("%s", sstr) != EOF){
        scanf("%s", lstr);
        int lens = strlen(sstr);
        int lenl = strlen(lstr);
        int i = 0, j = 0, isSame;
        while(i < lens){
            isSame = 0;
            j = 0;
            while(j < lenl){
                if(sstr[i] == lstr[j]){
                    isSame = 1;
                    break;
                }
                else j++;
            }
            if(!isSame) break;
            i++;
        }
        if(!isSame) printf("false\n");
        else printf("true\n");
    }
    return 0;
}