#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "my_mat.h"

void printmatrix(int matrix[10][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(void){
    char c;
    int matrix[10][10];
    while(c!= 'd' && c!= 'D'){
        c=getchar();
        if(c =='A'||c =='a'){
            getmatrix(matrix);
        }
        if(c=='B' || c=='b'){
            char temp[6];
           // printf("Please insert the two vertices you would like to check\n");
            temp[0]=getchar();
            fgets(temp,7,stdin);
            int ans= isconnected(matrix, temp[0]-'0', temp[2]-'0');
            printf(ans ? "true\n" : "false\n");
        }
        if(c=='C' || c=='c'){
            char temp[6];
           // printf("Please insert the two vertices you would like to check\n");
            temp[0]=getchar();
            fgets(temp,7,stdin);
            int ans= shortestpath(matrix,temp[0]-'0', temp[2]-'0');
            printf("%d\n", ans);
        }
        if(c=='P' || c=='p'){
            printmatrix(matrix);
        }
    }
    // printmatrix(matrix);
}
