#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

void printGraph(int graph[MAX][MAX], int V) {
    cout << "\nAdjacency Matrix Representation:\n";
    for(int i=1; i<=V; i++) {
        for(int j=1; j<=V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int start, int graph[MAX][MAX], int V) {
    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal Order: ";

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Graphical step: show which node is being visited
        cout << "\n[Visiting Node " << node << "]\n";

        for(int i=1; i<=V; i++) {
            if(graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                cout << " --> Enqueue " << i << endl;
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int graph[MAX][MAX] = {0};

    cout << "Enter edges (u v):\n";
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    printGraph(graph, V);

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    bfs(start, graph, V);

    return 0;
}
