#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Graph representation
int adj[MAX_NODES][MAX_NODES]; // 2D Adjacency Matrix
int visited[MAX_NODES];        // Track visited nodes (0 = unvisited, 1 = visited)
int numNodes;                  // Total number of nodes in graph

// --- Depth First Search (Recursive Function) ---
void dfs(int current) {
    // 1. Process and print the current node immediately upon entering
    printf("%d ", current);
    
    // 2. Mark this node as visited so we don't revisit it
    visited[current] = 1;

    // 3. Look for adjacent nodes (neighbors)
    for (int i = 0; i < numNodes; i++) {
        // If there is an edge AND the neighbor 'i' is NOT visited yet:
        if (adj[current][i] == 1 && !visited[i]) {
            // Immediately dive deep into neighbor 'i' via recursion
            dfs(i); 
        }
    }
}

// --- Wrapper Function to Reset Visited Tracker & Start DFS ---
void startDFS(int startNode) {
    // Clear visited array to all zeros
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from node %d: ", startNode);
    dfs(startNode);
    printf("\n");
}

int main() {
    numNodes = 5; // Nodes: 0, 1, 2, 3, 4

    // Initialize all graph edges to 0 (No connections)
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            adj[i][j] = 0;
        }
    }

    // Add undirected edges
    // Graph Structure:
    //    0 --- 1
    //    |   / |
    //    |  /  |
    //    2 --- 3 --- 4

    // Node 0 connections
    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][2] = 1; adj[2][0] = 1;

    // Node 1 connections
    adj[1][2] = 1; adj[2][1] = 1;
    adj[1][3] = 1; adj[3][1] = 1;

    // Node 2 connections
    adj[2][3] = 1; adj[3][2] = 1;

    // Node 3 connections
    adj[3][4] = 1; adj[4][3] = 1;

    // Run DFS starting from node 0
    startDFS(0);

    return 0;
}