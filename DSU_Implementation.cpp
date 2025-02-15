#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N];
int Size[N];

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
    cout<<"Enter no of vertices and edges :";
    cin>>V>>E;

    for(int i=1;i<=V;i++)Make(i);

    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter source and destination : ";
        cin>>u>>v;
        Union(u,v);
    }

    int component_ct=0;

    for(int i=1;i<=V;i++){
        if(parent[i]==i)component_ct++;
    }
    cout<<"Total component : "<<component_ct<<endl;

    return 0;

}