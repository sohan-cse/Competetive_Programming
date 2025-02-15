#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

void BFS(int &vtx,vector<int>g[]){
    vector<bool>vis(N,false);
    queue<int>q;
    vis[vtx]=true;
    q.push(vtx);
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        for(int&v:g[q.front()]){
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
            }
        }
        q.pop();
    }
    
}

int main(){
    int V,E;
    cout<<"Enter no of vertices and edeges :";
    cin>>V>>E;

    vector<int>g[N];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int vtx;
    cout<<"Enter starting vertex : ";
    cin>>vtx;
    BFS(vtx,g);

    return 0;
}