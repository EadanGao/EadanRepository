#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%[^\n]%*c", str);
    int length = strlen(str);

    int letter = 0, space = 0, number = 0, other = 0;

    for(int i = 0; i < length; i++){
        if(str[i] == ' ') space++;
        else if(str[i] >= 48 && str[i] <= 57) number++;
        else if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) letter++;
        else other++;
    }
    printf("%d\n%d\n%d\n%d\n", letter, space, number, other);

    return 0;
}