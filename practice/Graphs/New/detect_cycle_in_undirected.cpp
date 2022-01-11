//dfs
void DFSRec(adj, s, visited, parent){
    visited[s] = true;
    for(int i=0;i<adj[s].size();i++){
        if(visited[u] == false){
            if(DFSRec(adj, u, visited, s) == true)return true;
            else if(u!= parent)return true;
        }
    }
    return false;
}

void DFS(adj, V)
{
    vector<int> v(V, false);
    for(int i=0;i<V;i++){
        if(visited[i] == false){
            if(DFSRec(adj, i, visited, -1))return true;
        }
    }

    return false;
}