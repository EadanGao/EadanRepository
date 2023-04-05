#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I 1; V 5; X 10; L 50; C 100; D 500; M 1000;

int convert(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char * s){

    int number = 0, length = strlen(s), last = 0, now = 0;
    do{
        length--;
        now = convert(s[length]);
        number = now < last ? number - now : number + now;
        last = now;
    }while(length);

    return number;
}


int main(){
    char * roman_numeral = (char *) malloc (20 * sizeof(char));
    printf("roman numeral: ");
    scanf("%s", roman_numeral);

    printf("integer: %d", romanToInt(roman_numeral));   

    free(roman_numeral);
    return 0;
}

// int romanToInt(char * s){

//     int number = 0, length = strlen(s), last = 0, now = 0;
//     do{
//         length--;
//         switch(s[length]){
//             case 'I': now = 1; break;
//             case 'V': now = 5; break;
//             case 'X': now = 10; break;
//             case 'L': now = 50; break;
//             case 'C': now = 100; break;
//             case 'D': now = 500; break;
//             case 'M': now = 1000; break;
//         }
//         // now = convert(s[length]);
//         number = now < last ? number - now : number + now;
//         last = now;
//     }while(length);

//     return number;
// }