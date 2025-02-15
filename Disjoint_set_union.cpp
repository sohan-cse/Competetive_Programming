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

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b){
        if(Size[a]<Size[b]){
            swap(a,b);
        }
        parent[b]=a;
        Size[a]+=Size[b];
    }
}

int main(){
    int V,E;
    cout<<"Enter Number of Vertices and Edge : "<<endl;
    cin>>V>>E;
    for(int i=1;i<=V;i++){
        Make(i);
    }
    while(E--){
        int u,v;
        cout<<"Enter connected vertices : "<<endl;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_ct=0;
    for(int i=1;i<=V;i++){
        if(Find(i)==i)connected_ct++;
    }
    cout<<"Total Connected component :"<<connected_ct<<endl;
}