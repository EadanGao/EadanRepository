/* 描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
    输入描述：
    连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串 */
#include<stdio.h>
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
        for(int j = length; j < 8; j++) tart[j] = '0';
        memcpy(rst[i++], start, 8);
        rst[i - 1][8] = '\0';
    }
    for(int j = 0; j < i; j++) printf("%s\n", rst[j]);

    return 0;
}