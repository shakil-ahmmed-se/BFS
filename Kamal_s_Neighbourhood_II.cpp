#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int visited[1000];
vector<int> nd;

void dfs(int u){
    nd.push_back(u);
    visited[u] = true;
    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int x;
    cin>>x;
    dfs(x);
    cout<<nd.size()-1<<endl;

    
    return 0;
}
