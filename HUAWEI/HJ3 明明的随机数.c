/* 描述
明明生成了NN个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。

数据范围： 1 \le n \le 1000 \1≤n≤1000  ，输入的数字大小满足 1 \le val \le 500 \1≤val≤500 
输入描述：
第一行先输入随机整数的个数 N 。 接下来的 N 行每行输入一个整数，代表明明生成的随机数。 具体格式可以参考下面的"示例"。
输出描述：
输出多行，表示输入数据处理后的结果#include <stdio.h>

 */
void swap(int * a, int * b){
    int temp = *b;
    *b = *a;
    *a = temp;
    return ;
}

int main() {
    int num;
    scanf("%d", &num);
    int random[num];
    for(int i = 0; i < num; i++) scanf("%d", &random[i]);

    int * start = random;
    int pointer = 0;

    //bubble sort
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - 1; j++){
            if(start[j] == start[j + 1]){
                // remove repeatition
                for(int k = j; k > 0; k--) start[k] = start[k - 1];
                start++;
                i--;
                num--;
            }
            else if(start[j] > start[j + 1]) swap(&start[j], &start[j+1]);
        }
    }

    for(int i = 0; i < num; i++) printf("%d\n", start[i]);
    
    return 0;
}