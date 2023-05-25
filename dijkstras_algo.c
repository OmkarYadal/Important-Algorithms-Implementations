//Dijkstra's algorithm

#include<stdio.h>
#include<stdlib.h>

int main() {
    int cost[10][10],distance[10],path[10][10];
    int min,index = 1,i,j,n,v,p,row,column;

    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++)
            scanf("%d",&cost[i][j]);
    }
    printf("Enter the node to visit\n");
    scanf("%d",&v);

    printf("Enter paths for the selected node\n");
    scanf("%d",&p);

    printf("Enter the path matrix\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++)
            scanf("%d",&path[i][j]);
    }

    for(i=1; i<=p; i++) {
        distance[i] = 0;
        row = 1;
        for(j=1; j<n; j++) {
            if(row != v) {
                column = path[i][j+1];
                distance[i] = distance[i] + cost[row][column];
            }
            row = column;
        }
    }

    min = distance[1];

    for(i=1; i<=p; i++) {
        if(distance[i] <= min) {
            min = distance[i];
            index = i;
        }
    }
    printf("Minimum distance is %d\n",min);
    printf("Minimum distance path is\n");
    for(i=1; i<=n; i++) {
        if(path[index][i] != 0)
            printf("--> %d\n",path[index][i]);
    }
}
