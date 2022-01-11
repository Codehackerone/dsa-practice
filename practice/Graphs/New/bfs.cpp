#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v){
    for(int i=0;i<v;i++){        
        for(int x:adj[i]){
            cout<<x<<' ';
        }
        cout<<endl;
    }
}

void BFS_connected(vector<int> adj[], int v, int s){
    vector<bool> visited[v+1];
    for(int i=0;i<v;i++)visited[i]=false;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<<f<<" ";
        for(int v:adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


void BFS(vector<int> adj[], int v, int s, vector<bool> visited){    
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<<f<<" ";
        for(int v:adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFS_disconnected(vector<int> adj[], int v, int s){
    vector<int> visited(v+1, false);
    for(int i=0;i<v;i++){
        if(visited[i] == false)BFS(adj, v, s, visited);
    }

}

int main(){
    int V=4;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, V);

    return 0;
}