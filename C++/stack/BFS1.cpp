#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph){ 
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node= q.front();
        q.pop();
        cout<<node<<"";
        for(int neighbor:graph[node]){
        if(!visited[neighbor]){
            visited[neighbor]=true;
            q.push(neighbor);
            }
        }
    }
}

int main(){
    vector<vector<int>> graph={ {},{2,3},{1,4},{1,4},{2,3} };
    bfs(1,graph);
    cout<<endl;

    return 0;
}
