#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Graph representation
int adj[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int numNodes;

// --- Queue Data Structure for BFS ---
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_NODES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

// --- Breadth First Search ---
void bfs(int startNode) {
    // Reset visited array
    for (int i = 0; i < numNodes; i++) visited[i] = 0;

    printf("BFS Traversal starting from node %d: ", startNode);

    visited[startNode] = 1;
    enqueue(startNode);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < numNodes; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    numNodes = 5;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            adj[i][j] = 0;
        }
    }

    // Add undirected edges
    // 0 --- 1
    // |  /  |
    // | /   |
    // 2 --- 3 --- 4
    
    // Edges connected to 0
    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][2] = 1; adj[2][0] = 1;

    // Edges connected to 1
    adj[1][2] = 1; adj[2][1] = 1;
    adj[1][3] = 1; adj[3][1] = 1;

    // Edges connected to 2
    adj[2][3] = 1; adj[3][2] = 1;

    // Edges connected to 3
    adj[3][4] = 1; adj[4][3] = 1;

    // Run Traversals
    bfs(0);
    
    return 0;
}