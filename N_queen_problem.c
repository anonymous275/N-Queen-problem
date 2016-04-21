#include<stdio.h>
#include<stdlib.h>
#define n 16
int board[n][n];
void printboard(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}
int issafe(int row,int col){
    int i,j;
    for(i=0;i<col;i++){
        if(board[row][i])
            return 0;
    }
    for (i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j])
            return 0;
    }
    for (i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j])
            return 0;
    }
    return 1;
}
int solution(int col){
    int i;
    if(col>=n)
        return 1;
    for(i=0;i<n;i++){
            if(issafe(i,col)){
                board[i][col]=1;
                if(solution(col+1))
                    return 1;
                board[i][col]=0;
            }
        }
    return 0;
}
int main(){
    int i,j,a=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            board[i][j]=0;
    }
    /*if(solution(board,0))
        printf("no solution Exists\n");
    else*/
    a=solution(0);
    if(!a)
        printf("Solution Doesn't Exists");
    else{
        printf("1 represents the position of Queen\n");
        printboard();
    }
    return 0;
}
