#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> adj[N];
int level[N];
// bool visited[N]={false};
void bfs(int s){
    // bool visited[N] ={false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   
    int t;
    cin>> t;
    for(int i = 0; i< t;i++){
        int s,d;
        cin>>s>>d;
        bfs(s);
        if(level[d]) cout<<level[d]<<endl;
        else cout <<"-1"<<endl;
    }
    
    return 0;
}
