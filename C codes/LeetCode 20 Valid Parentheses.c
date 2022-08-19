#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char * s){
    if(s[0] == '\0') return false;
    int i = 0, temp = 0, length = strlen(s);
    char * cache = (char*) malloc(5000 * sizeof(char));

    while(i < length){
        switch(s[i]){
            case '(': *(cache + temp++) = '('; break;
            case '[': *(cache + temp++) = '['; break;
            case '{': *(cache + temp++) = '{'; break;
            default:
                if(!temp) return false;
                switch(s[i]){
                    case ')':
                        if(*(cache + temp - 1) == '('){
                            temp--;
                            break;
                        } 
                        else return false;
                    case ']': 
                        if(*(cache + temp - 1) == '['){
                            temp--;
                            break;
                        } 
                        else return false;
                    case '}': 
                        if(*(cache + temp - 1) == '{'){
                            temp--;
                            break;
                        } 
                        else return false;
                }
        }
        i++;
    }
    if(temp) return false;
    return true;
}


int main(){
    char str[100];

    scanf("%s", str);
    printf("\n%d\n", isValid(str));
    
    return 0;
}



// bool isValid(char * s){
//     if(s[0] == '\0') return false;
//     int i = 0, temp = 0, length = strlen(s);
//     char * cache = (char*) malloc(5000 * sizeof(char));

//     while(i < length){
//         switch(s[i]){
//             case ')':
//                 if(!temp) return false;
//                 if(*(cache + temp - 1) == '('){
//                     temp--;
//                     break;
//                 } 
//                 else return false;
//             case ']': 
//                 if(!temp) return false;
//                 if(*(cache + temp - 1) == '['){
//                     temp--;
//                     break;
//                 } 
//                 else return false;
//             case '}': 
//                 if(!temp) return false;
//                 if(*(cache + temp - 1) == '{'){
//                     temp--;
//                     break;
//                 } 
//                 else return false;
//             case '(': *(cache + temp++) = '('; break;
//             case '[': *(cache + temp++) = '['; break;
//             case '{': *(cache + temp++) = '{'; break;
//             default: return false;
//         }
//         i++;
//     }
//     if(temp) return false;
//     return true;
// }

// bool isValid(char * s){
//     if(s[0] == '\0') return false;
//     int i = 0, temp = 0, length = strlen(s);
//     char * cache = (char*) malloc(5000 * sizeof(char));

//     while(i < length){
//         switch(s[i]){
//             case '(': 
//                 *(cache + temp++) = ')';
//                 break;
//             case '[': 
//                 *(cache + temp++) = ']';
//                 break;
//             case '{': 
//                 *(cache + temp++) = '}';
//                 break;
            
//             default:
//                 if(temp && *(cache + temp - 1) == s[i]) {
//                     temp--;
//                     break;
//                 }
//                 else return false;
//         }
//         i++;
//     }
//     if(temp) return false; 
//     return true;
// }



// bool isValid(char *s) {
//     char* stack = (char*) malloc(5000*sizeof(char));
//     char* temp = stack;
//     printf("stack = %d, temp = %d\n", stack, temp);
//     while(*s!='\0') {
//         if(*s == '(' ) {
//             *stack = ')';
//             stack++;
//         }
//         else if(*s == '[' ) {
//             *stack = ']';
//             stack++;
//         }
//         else if(*s == '{' ) {
//             *stack = '}';
//             stack++;
//         }
//         else {
//             if((temp < stack) && (*s == *--stack)) ;
//             else return false;
//         }
        
//         s++;
//     }
//     //if stack address is different from initial address, then something is wrong    
//     if(stack != temp) return false;

//     return true;
// }
