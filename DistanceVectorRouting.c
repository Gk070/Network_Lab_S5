# include <stdio.h>

# define INF 999
# define SIZE 25

int main(){

    int i, j, k, n, dist[SIZE][SIZE];

    printf("Enter no:of routers : ");
    scanf("%d", &n);

    printf("Enter the cost matrix\n(999 for unreachable router)\n(0 for source to source)\n");
    for(i = 0; i < n; i ++){
        printf("Router %d : ", i + 1);
        for(j = 0; j < n; j++){
            scanf("%d", &dist[i][j]);
        }
        printf("\n");
    }

    printf("\nInitial Routing Table\n");
    printf("---------------------\n");
    for(i = 0; i < n; i++){
        printf("| Router %d\t|", i + 1);
        for(j = 0; j < n; j++){
            printf(" %2d\t|", dist[i][j]);
        }
    }
    printf("\n");

    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Final Routing Table\n");
    printf("-------------------\n");
    for(i = 0; i < n; i++){
        printf("| Router %d\t|", i + 1);
        for(j = 0; j < n; j++){
            printf(" %2d\t|", dist[i][j]);
        }
        printf("\n");
    }

    return 0;

}