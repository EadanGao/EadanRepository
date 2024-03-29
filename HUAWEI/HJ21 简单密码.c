/* 描述
现在有一种密码变换算法。
九键手机键盘上的数字与字母的对应： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0，把密码中出现的小写字母都变成九键键盘对应的数字，如：a 变成 2，x 变成 9.
而密码中出现的大写字母则变成小写之后往后移一位，如：X ，先变成小写，再往后移一位，变成了 y ，例外：Z 往后移是 a 。
数字和其它的符号都不做变换。
数据范围： 输入的字符串长度满足 1 \le n \le 100 \1≤n≤100 
输入描述：
输入一组密码，长度不超过100个字符。

输出描述：
输出密码变换后的字符串 */

#include <stdio.h>
#include <string.h>

int main() {
    char password[102];
    scanf("%s", password);
    int i = strlen(password);

    while(--i > -1){
        if(password[i] >= 'A' && password[i] < 'Z') password[i] += 33;
        else if(password[i] == 'Z') password[i] ='a';
        else if(password[i] >= 'a' && password[i] <= 'c') password[i] = '2';
        else if(password[i] >= 'd' && password[i] <= 'f') password[i] = '3';
        else if(password[i] >= 'g' && password[i] <= 'i') password[i] = '4';
        else if(password[i] >= 'j' && password[i] <= 'l') password[i] = '5';
        else if(password[i] >= 'm' && password[i] <= 'o') password[i] = '6';
        else if(password[i] >= 'p' && password[i] <= 's') password[i] = '7';
        else if(password[i] >= 't' && password[i] <= 'v') password[i] = '8';
        else if(password[i] >= 'w' && password[i] <= 'z') password[i] = '9';
    }
    printf("%s\n", password);

    return 0;
}