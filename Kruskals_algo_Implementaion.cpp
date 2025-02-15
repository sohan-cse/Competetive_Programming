#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N],Size[N];

void Make(int v){
    parent[v]=v;
    Size[v]=1;
}

int Find(int v){
    if(v==parent[v])return v;
    return parent[v]=Find(parent[v]);
}

void Union(int u,int v){
    int rt_u=Find(u);
    int rt_v=Find(v);

    if(rt_u==rt_v)return;
    if(Size[rt_u]<Size[rt_v])swap(rt_u,rt_v);
    parent[rt_v]=rt_u;
    Size[rt_u]+=Size[rt_v];
}

int main(){
    int V,E;
    cout<<"Enter no of vertices and edges : ";
    cin>>V>>E;
    for(int i=1;i<=V;i++)Make(i);
    
    vector<pair<int,pair<int,int>>>edges;

    for(int i=0;i<E;i++){
        int u,v,wt;
        cout<<"Enter weight,source & destination : ";
        cin>>wt>>u>>v;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());
    int total_wt=0;

    for(auto&edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(Find(u)==Find(v))continue;

        Union(u,v);
        total_wt+=wt;
        cout<<u<<"-->"<<v<<"  weight :"<<wt<<endl;
    }

    cout<<"Total cost of MST : "<<total_wt<<endl;

    return 0;
}