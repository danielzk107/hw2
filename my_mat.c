#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void getmatrix(int matrix[10][10]){
    //printf("Please enter your matrix\n");
    char temp=getchar();
    temp=getchar();//calling getchar twice in order to get rid of the space before the first number, so the matrix would ahve all the correct numbers in the correct places.
    matrix[0][0]= temp-'0';
    for (int i = 0; i < 10 ; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(i!=0 || j!=0){
                matrix[i][j]=0;
            }
            char x=getchar();
            while(isdigit(x)){
                matrix[i][j]=matrix[i][j]*10;
                matrix[i][j]+=x-'0';
                x=getchar();
            }
        }
    }
}
int isconnected(int matrix[10][10], int a, int b){
    if(a==b){
        return false;
    }
    int visited[10];
    int queue[10];
    int first = 0;
    int last=0;
    int visitedindex=0;
    for (int i = 0; i < 10; i++)
    {
        visited[i]=-1;
        if(matrix[a][i]>0){
            if(i==b){
                return true;
            }
            queue[first]=i;
            first++;
            last++;
        }
    }
    for (; first<10; first++)
    {
        queue[first]=-1;
    }
    first=0;
    visited[visitedindex]=a;
    visitedindex++;
    bool whilecondition = true;
    while(last<10 && whilecondition){
        int x=queue[first];
        first++;
        visited[visitedindex]=x;
        visitedindex++;
        for (int i = 0; i < 10; i++)
        {
            if(matrix[x][i]>0){
                int condition= i!=a;
                if(i==b){
                    return true;
                }
                for (int index = first; index <= last; index++)
                {
                    if(i == queue[index] || i== visited[index]){
                        condition=false;
                    }
                }
                if(condition){
                    if(last>=10){
                        break;
                    }
                    queue[last] = i;
                    last++; 
                }
            }
        }
        whilecondition= queue[first]!=-1;
    }
    return false;
    
}
int shortestpath(int matrix[10][10], int a, int b){
    if(!isconnected(matrix,a,b)){
        return -1;
    }
    int dist[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(i==j){
                dist[i][j]=0;
            }
            else if(matrix[i][j]>0){
                dist[i][j]=matrix[i][j];
            }
            else{
                dist[i][j]=(__INT_MAX__)/2;
            }
        }
    }
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }   
        }
    }
    return dist[a][b];
}
