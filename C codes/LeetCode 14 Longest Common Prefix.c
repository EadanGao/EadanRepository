#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if (!strsSize) return "";
    if(strs[0][0] == '\0') return "";
    

    int cmm = 0;
    char cmm_letter;
    char * rtn;
    
    do{
        cmm_letter = strs[0][cmm];
        for(int i = 1; i < strsSize; i++){
            if(cmm_letter == strs[i][cmm]) continue;
            else{
                rtn = (char *) malloc((cmm + 1) * sizeof(char));
                memcpy(rtn, strs[0], cmm);
                rtn[cmm] = '\0';
                return rtn;
            }
        }
        cmm++;
    }while(cmm && (strs[0][cmm] != '\0'));

    if(!cmm)  return "";
    rtn = (char *) malloc((cmm + 1) * sizeof(char));
    memcpy(rtn, strs[0], cmm);
    rtn[cmm] = '\0';
    return rtn;
}

int main(){
    int strsSize;
    printf("strsSize: ");
    scanf("%d%*c", &strsSize);
    char words[220][220];
    char *strs[220];

    for(int i = 0; i < strsSize; i++) scanf("%[^\n]%*c", words[i]);
    for(int i = 0; i < strsSize; i++) strs[i] = words[i];

    printf("%s\n", longestCommonPrefix(strs, strsSize));
    return 0;
}