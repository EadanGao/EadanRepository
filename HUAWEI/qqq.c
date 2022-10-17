#include<stdio.h>
#include<string.h>
  ///*深度优先搜索
  //num：输入的数字集
  //sign：存储某个数字是否被遍历过0未遍历，1已经遍历
  //number：当前运算结果
  //com：存储运算过程中的 + - * /
  //seq：按顺序存储遍历过程中使用数字的先后顺序
  //*/
int dfs(int *num,int *sign,int number,char *com,int *seq){
    int mole =0;
    for(int i=0;i<4;i++){//统计已经遍历的个数
        if(sign[i] == 1){
            mole ++;
        }
    }
    if(mole == 4){
        printf("%d%c%d%c%d%c%d = %d\n", seq[0], com[0], seq[1], com[1], seq[2], com[2], seq[3], number);
    }
    if(number == 24 && mole == 4){//判断成功的条件4个数字全部遍历完后运算结果为24，做输出展示。
        for(int i=0;i<4;i++){//将数字翻译成输入进来是的A、J、Q、K。
            if(seq[i]==1)printf("A");
            else if(seq[i] == 11)printf("J");
            else if(seq[i] == 12)printf("Q");
            else if(seq[i] == 13)printf("K");
            else {
                printf("%d",seq[i]);
            }
            if(i==0)printf("%c",com[0]);//同时输出 + - * /
            if(i==1)printf("%c",com[1]);
            if(i==2)printf("%c",com[2]);
        }
        return 1;
    }else if(mole == 4 && number!=24){//如果四个数字已经全部便利完，结果不是：失败return结束
        return 0;
    }
    for(int i=0;i<4;i++){
        if(sign[i] != 1){//便利数字集如果还没有被访问，访问该数字
            sign[i]=1;//标记为1：num[i]已经被使用过
            com[mole-1]='+';//运算符号集记录运算过程
            seq[mole]=num[i];//运算数字顺序集记录数字计算过程
            if(dfs(num,sign,number+num[i],com,seq)){//做深度搜索
                return 1;
            }
            com[mole-1]='-';
            if(dfs(num,sign,number-num[i],com,seq)){
                return 1;
            }
            com[mole-1]='*';
            if(dfs(num,sign,number*num[i],com,seq)){
                return 1;
            }
            com[mole-1]='/';
            if(number%num[i] == 0 && dfs(num,sign,number/num[i],com,seq)){
                return 1;
            }
            sign[i]=0;
        }
    }
    return 0;
}

int main(){
    char str[24];
    gets(str);
    int num[4], size=0;
//     printf("%d\n",strlen(str));
    for(int i=0;i<strlen(str);i++){
        if(str[i] == ' '){
            continue;
        }
        if((str[i]=='J' && str[i] == 'O')||(str[i] == 'j')){
            printf("ERROR");
            return 0;
        }else if(str[i]=='J'){
            num[size++] = 11;
            continue;
        }
        switch(str[i]){
            case 'A':{num[size++]=1;continue;}
            case 'Q':{num[size++]=12;continue;}
            case 'K':{num[size++]=13;continue;}
        }
        if(str[i]=='1' && str[i+1]=='0'){
            num[size++]=10;
        }else if( str[i] >= '2' && str[i]<='9'){
            num[size++] = str[i]-'0';
        }
    }
    int sign[4]={0},seq[4];
    char com[3];

    for(int i=0;i<4;i++){
        sign[i]=1;
        seq[0]=num[i];
        if(dfs(num,sign,num[i],com,seq)){
            return 0;
        }
        sign[i]=0;
    }
    printf("NONE");
    return 0;
}
