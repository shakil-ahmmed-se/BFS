#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];


void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    // cout<<"parent "<<s<<" ";
    while (!q.empty())
    {
        int u = q.front();
        
        q.pop();
        
        
        for(int v : adj[u]){
            
            if(visited[v]) continue;
            // cout<<v<<" ";
            q.push(v);
            visited[v] = true;
            
        }
    
    }
    
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
    bfs(1);
    
    
    return 0;
}