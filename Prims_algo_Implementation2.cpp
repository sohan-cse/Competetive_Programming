#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

pair<int,int>*minVtx(vector<pair<int,pair<int,int>>>adjList[],vector<bool> &vis,int &u){
    int min_wt=INT_MAX,minIdx;
    for(auto&edge:adjList[u]){
        if(!vis[edge.first]&&edge.first<min_wt){
            min_wt=edge.first;
            minIdx=edge.second;
        }
    }
    return {minIdx,min_wt};
}

void Prims_MST(vector<pair<int,int>>adjList[],int &V,int &vtx){
    vector<bool>vis(N,false);
    vector<pair<int,int>>parent;
    vis[vtx]=true;
    int u=vtx;
    int wt_ct=0;
    for(int i=0;i<V-1;i++){
        pair<int,int>idx_wt=minVtx(adjList,vis,u);
        parent.push_back(idx_wt);
        u=idx_wt.first;
        wt_ct+=idx_wt.second;
        vis[u]=true;
    }

    cout<<"Total cost : "<<wt_ct<<endl;
}

void INPUT_GRAPH(int &V,int &E){
    vector<pair<int,int>>adjList[N];
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjList[u].push_back({wt,v});
        adjList[v].push_back({wt,u});
    }
    int vtx;
    cout<<"Enter starting vertex : ";
    cin>>vtx;
    Prims_MST(adjList,V,vtx);
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges : ";
    cin>>V>>E;
    INPUT_GRAPH(V,E);
    return 0;
}