#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

void DFS(vector<int>g[],int &parent,vector<bool>&vis){
    cout<<"parent="<<"  "<<parent<<endl;
    vis[parent]=true;
    for(auto&child:g[parent]){
        if(vis[child])continue;
        DFS(g,child,vis);
    }

}
int main(){
    int V,E;
    cout<<"Enter no of vertices and edges :  ";
    cin>>V>>E;
    vector<int>g[N];
    vector<bool>vis(N,false);
    cout<<"source & destination "<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int vtx;
    cout<<"Enter starting vertex :";
    cin>>vtx;
    DFS(g,vtx,vis);
}