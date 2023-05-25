//Prim's algorithm

#include<stdio.h>
#include<stdlib.h>
void prims(int,int [10][10]);
int main()
{
    int i,j,n,cost[10][10];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    prims(n,cost);
    return 0;
}
void prims(int n,int cost[10][10])
{
    int i,j,v,u,min,mincost = 0,visited[10],ne = 1;

    for(i=1; i<=n; i++)
        visited[i] = 0;
    printf("Edges considered for MST\n");
    visited[1] = 1;

    while(ne < n) {
        for(i=1,min=999; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j] < min) {
                    if(visited[i] != 0) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }

        if(visited[u] == 0 || visited[v] == 0) {
            printf("Edge (%d,%d) = %d\n",u,v,min);
            ne++;
            mincost = mincost + min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("Cost of constructing MST is %d\n",mincost);
}
