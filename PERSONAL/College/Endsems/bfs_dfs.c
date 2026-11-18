#include <stdio.h>
#define MAX 10

// Graph properties
int adj[MAX][MAX];
int visited[MAX];
int n;

// Queue properties
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value){
    if (rear == MAX - 1){
        printf("Full");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue(){
    if (front == -1){
        printf("Empty");
        return -1;
    }

    int value = queue[front];
    printf(" %d ", value);
    front++;
    if (front > rear){
        front = -1;
        rear = -1;
    }
    return value;
}

// bfs
void bfs(int start){
    enqueue(start);
    visited[start] = 1;

    while (front != -1){
        int u = dequeue();
        for (int i = 0; i < n; i++){
            if (adj[u][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// dfs
void dfs(int start){
    visited[start] = 1;
    printf(" %d ", start);

    for (int i = 0; i < n; i++){
        if (adj[start][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    n = 5;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Add edges (undirected graph: 0-1, 0-2, 1-3, 1-4)
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;

    printf("BFS:");
    bfs(0);

    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    printf("\nDFS:");
    dfs(0);
    printf("\n");

    return 0;
}
