#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

// Queue for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value){
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue(){
    if(front == -1 || front > rear) return -1;
    int value = queue[front];
    front++;
    return value;
}

// 1. BFS (Breadth-First Search)
void bfs(int start){
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    printf("BFS: ");
    while(front != -1 && front <= rear){
        int current = dequeue();
        printf("%d ", current);

        int i = 0;
        while(i < n){
            if(adj[current][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
            i++;
        }
    }
    printf("\n");
}

// 2. DFS (Depth-First Search)
void dfs(int current){
    printf("%d ", current);
    visited[current] = 1;

    int i = 0;
    while(i < n){
        if(adj[current][i] == 1 && visited[i] == 0){
            dfs(i);
        }
        i++;
    }
}

int main(){
    n = 5; // Vertices 0, 1, 2, 3, 4

    // Initialize matrix to 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }

    // Add edges (undirected graph: 0-1, 0-2, 1-3, 1-4)
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;

    // Run BFS starting from vertex 0
    bfs(0); // Output: 0 1 2 3 4

    // Reset visited array before running DFS
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("DFS: ");
    dfs(0); // Output: 0 1 3 4 2
    printf("\n");

    return 0;
}