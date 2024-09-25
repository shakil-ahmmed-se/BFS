#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];

void dfs(int u ){
    visited[u] = true;
        cout<<u<<" ";
    for(int v : adj[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    int cc = 0;
    for (int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        cout<<"component: ";
        dfs(i);
        cout<<endl;
        cc++;

    }
    cout<<"number of comp : "<<cc<<endl;
    
    return 0;
}