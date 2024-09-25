#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool visited[1001] = {false};
vector<int> ans;

void bfs(int s){
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int count = 1; 
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for(int v :adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v]  = true;
            count++;
        }
    
    }
    if(count>1){
        ans.push_back(count);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]) bfs(i);
    }

    sort(ans.begin(),ans.end());
    for (int i = 1; i <= ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
