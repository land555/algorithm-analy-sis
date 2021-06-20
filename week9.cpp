#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXSIZE=1001;
int C[MAXSIZE][MAXSIZE];
char rec[MAXSIZE][MAXSIZE];
char X[MAXSIZE],Y[MAXSIZE];

void Lcs(int n,int m){
 for(int i=0;i<=n;i++)C[i][0]=0;
    for(int i=0;i<=m;i++)C[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i]==Y[j]){
                C[i][j]=C[i-1][j-1]+1;
                rec[i][j]='Q';//×óÉÏ 
            }else if(C[i-1][j]>=C[i][j-1]){
                C[i][j]=C[i-1][j];
                rec[i][j]='W';//ÉÏ 
            }else{
                C[i][j]=C[i][j-1];
                rec[i][j]='A';//×ó 
            }
        }
    }
}
void PrintLcs(int n,int m){
    int i=n,j=m;
    if(i==0||j==0)return;
    if(rec[i][j]=='Q'){
        PrintLcs(i-1,j-1);
        printf("%c",X[i]);
    }else if(rec[i][j]=='W'){
        PrintLcs(i-1,j);
    }else{
        PrintLcs(i,j-1);
    }
}
int main(){ 
    scanf("%s %s",X+1,Y+1);
    size_t n=strlen(X+1);
    size_t m=strlen(Y+1);
    Lcs(n,m);
    PrintLcs(n,m);
}

