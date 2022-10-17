#include <stdio.h>
#include <string.h>

int pointer = 0;
int matrix[26][2] = {0};

int compute(char *equation, int rc[][2], int index){
    int len = strlen(equation);
    int cnt = 0;
    
    int i = pointer;
    
    int j = index;
    
    while(i < len){
        if(equation[i] == '('){
            pointer = i + 1;
            cnt += compute(equation, rc, j);
            // printf("cnt = %d\n", cnt, j);
            i = pointer;
            j++;
        }
        if(equation[i] >= 'A' && equation[i] <= 'Z'){
            matrix[j][0] = rc[equation[i] - 'A'][0];
            matrix[j][1] = rc[equation[i] - 'A'][1];
            j++;
            i++;
        }
        if(equation[i] == ')'){
            pointer = i + 1;
            break;
        }
    }
    // for(int k = 0; k < j; k++){
    //     // printf("%d %d\n", matrix[i][0], matrix[i][1]);
    //     printf("%d %d\n", matrix[k][0], matrix[k][1]);
    // }
    // printf("index = %d, j = %d\n", index, j);

    for(int k = index; k < j - 1; k++){
        // printf("%d %d %d\n", matrix[k][0], matrix[k][1], matrix[k + 1][1]);
        cnt += matrix[k][0] * matrix[k][1] * matrix[k + 1][1];
        matrix[k + 1][0] = matrix[k][0];
    }
    // printf("\n");
    
    matrix[index][0] = matrix[j - 1][0], matrix[index][1] = matrix[j - 1][1];

    for(int k = index + 1; k < j ; k++){
        matrix[k][0] = 0;
        matrix[k][1] = 0;
    }
    return cnt;

}

int main() {
    // int n;
    // scanf("%d", &n);
    // int rc[n][2]; // 0 row, 1 column
    // for(int i = 0; i < n; i++) scanf("%d%d", &rc[i][0], &rc[i][1]);
    // char equation[10];
    // scanf("%s", equation);

    int n = 3;
    int rc[n][2];
    rc[0][0] = 50, rc[0][1] = 10, rc[1][0] = 10, rc[1][1] = 20, rc[2][0] = 20, rc[2][1] = 5;
    char equation[50] = "(A(BC))";

    int cnt = compute(equation, rc, 0);
    printf("%d", cnt);


    return 0;
}