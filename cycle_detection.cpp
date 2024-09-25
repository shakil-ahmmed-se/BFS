#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];

bool dfs(int u,int p = -1){
    bool cycleExist = false;
    visited[u] = true;
    for(int v : adj[u]){
        if(v ==  p) continue;
        if(visited[v]) return true;
        cycleExist = cycleExist | dfs(v,u);
    }
    return cycleExist;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool isCycle = false;
    for (int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        isCycle = isCycle | dfs(i);
    }
    if(isCycle) cout<<"Cycle Detected\n";
    else cout<<"No Cycle Detected\n";
    
    
    return 0;
}