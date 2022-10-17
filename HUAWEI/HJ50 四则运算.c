#include <stdio.h>
#include <string.h>

int number[1001];
int j = 0;

int compute(char *str,int * i){
    int length = strlen(str);
    int pointer = j; 
    char operator = '+';

    while(*i < length){
        int temp = 0;

        if(str[*i] == '+' || str[*i] == '-' || str[*i] == '*' || str[*i] == '/'){
            operator = str[*i];
            *i += 1;
        }
        if(str[*i] == '{' || str[*i] == '[' || str[*i] == '('){
            *i += 1;
            temp = compute(str, i);
        }

        while(* i < length && str[* i] >= 48 && str[* i] <= 57){
            if(temp) temp *= 10;
            temp += (str[*i] - 48);
            *i += 1;
        }

        switch(operator){
            case'+': number[j++] = temp; break;
            case'-': number[j++] -= temp; break;
            case'*': number[j - 1] *= temp; break;
            case'/': number[j - 1] /= temp; break;
        }
        if(str[*i] == '}' || str[*i] == ']' || str[*i] == ')'){
            *i += 1;
            break;
        }

    }
    int rst = 0;
    for(int k = pointer; k < j; k++){
        rst += number[k];
        number[k] = 0;
    } 
    j = pointer;


    return rst;

}


int main() {
    char str[1001];
    scanf("%s", str);
    int rst = 0, i = 0;
    rst = compute(str, &i);
    printf("%d\n", rst);

    return 0;
    }