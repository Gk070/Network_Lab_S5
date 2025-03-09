# include <stdio.h>
# include <limits.h>

int main(){

    int n, i, j, d, adj[50][50], source, visited[50], dist[50], round, v, min, min_index;

    printf("Enter the no:of nodes : ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix : \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    printf("Enter the source node : ");
    scanf("%d", &source);
    dist[source] = 0;

    for(round = 0; round = n - 1; round++){
        min = INT_MAX;
        min_index = -1;

        for(v = 0; v < n; v++){
            if(!visited[v] && dist[v] < min){
                min = dist[v];
                min_index = v;
            }
        }

        if(min_index == -1){
            break;
        }
        visited[min_index] = 1;

        for(d = 0; d < n; d++){
            if(!visited[d] && adj[min_index][d] && dist[min_index] != INT_MAX && dist[d] > adj[min_index][d] + dist[min_index]){
                dist[d] = adj[min_index][d] + dist[min_index];
            }
        }
    }

    printf("Vertex distance from source\n");
    for(i = 0; i < n; i++){
        printf("Vertex %d -> Distance %d\n", i + 1, dist[i]);
    }

    return 0;

}