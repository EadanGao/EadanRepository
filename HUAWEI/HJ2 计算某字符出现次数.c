/* 描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

数据范围： 1 \le n \le 1000 \1≤n≤1000 
输入描述：
第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字符。

输出描述：
输出输入字符串中含有该字符的个数。（不区分大小写字母） */

#include <stdio.h>
#include<string.h>
int hashTable[43];

int main() {
    char str[1005];
    char target;
    scanf("%[^\n]%*c", str);
    scanf("%c", &target);
    int len = strlen(str);
    
    if(target > 90) target = target - 32;

    while(--len >= 0){
        // printf("str[len] = %c, %d len = %d\n", str[len], str[len], len);
        if(str[len] < 48) continue;
        if(str[len] > 90) str[len] = str[len] - 32;
        // printf("str[len] = %c, %d len = %d\n\n", str[len], str[len], len);
        hashTable[str[len] - 48]++;
    }
    printf("%d\n", hashTable[target - 48]);
    return 0;
}