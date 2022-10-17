#include <stdio.h>
#include <string.h>

int main() {
    char str1[151], str2[151];
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i = 0, same = 0;;

    while(i < len1){
        int j = 0, cnt = 0;
        while(j < len2){
            cnt = 0;
            while(str1[i + cnt] == str2[j + cnt] && i + cnt < len1 && j + cnt < len2) cnt++;
            same = same < cnt ? cnt : same;
            j++;
        }
        i++;
    }
    printf("%d\n", same);

    return 0;
}