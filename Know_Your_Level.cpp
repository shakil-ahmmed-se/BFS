#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
bool visited[100000];
int level[100000];

void bfs(int s){
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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
    bfs(0);
    int x;
    cin>>x;
   vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(level[i] == x) ans.push_back(i);
        
    }
    if(ans.empty()){
        cout<<"-1"<<endl;
    }
    else{
        for (int i = 0; i < ans.size() ; i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    
    return 0;
}