#include <stdio.h>
#include <string.h>

int main() {
    char alphabet[26] = {0}, key[101], Alphabet[26], words[101];
    for(int i = 0; i < 26; i++) Alphabet[i] = i + 97;

    scanf("%s", key);
    scanf("%s", words);

    int len = strlen(key);

    int pointer = 1;
    alphabet[0] = key[0];
    Alphabet[key[0] - 97] = 0;

    for(int i = 1; i < len; i++){
        int j = 0;
        while(j < pointer && key[i] != alphabet[j]) j++;
        if(key[i] == alphabet[j]) continue;
        else{
            alphabet[pointer] = key[i];
            Alphabet[key[i] - 97] = 0;
            pointer++;
        }
    }

    while(pointer < 26){
        int i = 0;
        while(!Alphabet[i] && i < 26) i++;
        alphabet[pointer++] = Alphabet[i];
        Alphabet[i] = 0;
    }

    int len2 = strlen(words);

    for(int i = 0; i < len2; i++) words[i] = alphabet[words[i] - 97];
    printf("%s\n", words);

    return 0;
}