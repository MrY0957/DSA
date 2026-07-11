#include<iostream>
using namespace std;

#define max 100

void dfs(int start, int graph[max][max], int V){
    bool visited[max]={false};
    int stack[max];
    int top=-1;

    int result[max];
    int idx=0;

    stack[++top]=start;
    visited[start]=true;

    cout<< "DFS traversal(with stack steps): \n";

    while(top>= 0){
        int node=stack[top--];
        cout<<"Visit: "<<node<<"\n";

        result[idx++]= node;

        for(int i=V; i>=1; i--){
            if(graph[node][i]==1 && !visited[i]){
                visited[i]=true;
                stack[++top]=i;
                cout<<" Push: "<< i<<"(stack top="<< top<<")\n";
            }
        }
    }

    cout<< "\nFinal DFS  traversal Array: ";
    for(int i=0; i<idx; i++){
        cout<< result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges: ";
    cin>> V>> E;

    int graph[max][max]={0};

    cout<<"Enter edges (u v): \n";
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int start;
    cout<<"Enter starting node: ";
    cin>>start;

    dfs(start, graph, V);

    return 0;
}
