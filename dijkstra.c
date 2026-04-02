#include <stdio.h>
#include <limits.h>

#define V 6

int min(int dist[], int visited[]) {
    int min = INT_MAX, index;
    int i;

    for (i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};
    int i, j, u;

    for (i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (i = 0; i < V - 1; i++) {
        u = min(dist, visited);
        visited[u] = 1;

        for (j = 0; j < V; j++) {
            if (!visited[j] && graph[u][j] &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Vertex\tDistance\n");
    for (i = 0; i < V; i++)
        printf("%c\t%d\n", 65 + i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0,1,2,0,0,0},
        {1,0,0,5,1,0},
        {2,0,0,2,3,0},
        {0,5,2,0,2,2},
        {0,1,3,2,0,1},
        {0,0,0,2,1,0}
    };

    dijkstra(graph, 0);
    return 0;
}
