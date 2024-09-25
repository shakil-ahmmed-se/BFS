#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int visited[1000];

void dfs(int u){
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
        adj[v].push_back(u);
    }
    int x;
    cin>>x;
    dfs(x);
    cout<<adj[x].size()<<endl;
    // int count = 0;
    // for(int i=0; i< n; i++){
    //     if(visited[i]) count++;
    // }
    // cout<<count-1<<endl;
    
    return 0;
}
