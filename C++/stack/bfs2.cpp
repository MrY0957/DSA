#include <iostream>
using namespace std;

#define MAX 100   // maximum vertices

void bfs(int start, int graph[MAX][MAX], int V) {
    bool visited[MAX] = {false};
    int q[MAX];          // manual array as queue
    int front = 0, rear = 0;

    visited[start] = true;
    q[rear++] = start;   // enqueue start node

    while(front < rear) {   // queue not empty
        int node = q[front++];   // dequeue
        cout << node << " ";

        // check neighbors
        for(int i = 1; i <= V; i++) {
            if(graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;   // enqueue neighbor
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int graph[MAX][MAX] = {0};

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "BFS Traversal: ";
    bfs(start, graph, V);
    cout << endl;

    return 0;
}
