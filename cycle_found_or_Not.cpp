#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];

bool dfs(int u, int p = -1){
    bool isCycleExits = false;
    visited[u]= true;

    for(int v : adj[u]){
        if(v == p) continue;
        if(visited[v]) return true;
        isCycleExits = isCycleExits | dfs(v,u);
    }
    return isCycleExits;
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
    if(dfs(1)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}