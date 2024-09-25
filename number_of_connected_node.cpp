#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool visited[10001];
int level[10001];

void dfs(int u ){
    // cout<<u<<" ";
    visited[u] = true;
    
    for(int v : adj[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}
 
void bfs(int s){
    queue<int> q;
    q.push(s);
    level[s] = 0;
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            
            
        }
    }
    
}

int main(){
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
       
        dfs(i);
         cc++;
    }
    cout<<"Number of connect component : "<<cc<<endl;

    
    
    return 0;
}