//kruskal's algorithm

#include<stdio.h>
#include<stdlib.h>

int i,j,k,a,b,u,v,n,ne = 1;
int min,mincost = 0,cost[10][10],parent[10];

int fipar(int);
int uni(int,int);

int main() {

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
    printf("MST : ");

    while(ne < n) {
        for(i=1,min=999; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = fipar(u);
        v = fipar(v);

        if(uni(u,v)) {
            printf("%d Edge (%d,%d) = %d\n",ne++,a,b,min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("The minimum cost is %d\n",mincost);
}
int fipar(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}
int uni(int i,int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
