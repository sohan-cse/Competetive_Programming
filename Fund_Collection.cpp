#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool vis[N];
void bfs(int vertex,int n)
{
    queue<int>q;
    q.push(vertex);
    vis[vertex]=true;
    while(!q.empty())
    {
        int cur_v=q.front();
        q.pop();
        for(int child : g[cur_v])
        {
            if(!vis[child] && child>cur_v)
            {
                q.push(child);
                vis[child]=true;
            }
        }
    }
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans=false;
        }
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
 {
     int t;
     cin>>t;
     while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int v1,v2;
            cin>>v1>>v2;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        bfs(1,n);
     }
 }
 
