#include<bits/stdc++.h>
using namespace std;

int min_KEY(vector<int>&key,vector<bool>&vis,int V){
    int min=INT_MAX;
    int minVtx;
    for(int vtx=0;vtx<V;vtx++){
        if(!vis[vtx] && key[vtx]<min){
            min=key[vtx];
            minVtx=vtx;
        }
    }
    return minVtx;
}

void prim_MST(vector<vector<int>>&G,int V){
    vector<int>parent(V,-1);
    vector<int>key(V,INT_MAX);
    vector<bool>vis(V,false);

    key[0]=0;
    parent[0]=-1;//starting  vertex

    for(int i=0;i<V-1;i++){
        int u=min_KEY(key,vis,V);
        vis[u]=true;

        for(int v=0;v<V;v++){
            if(G[u][v]&&!vis[v]&&G[u][v]<key[v]){
                parent[v]=u;
                key[v]=G[u][v];
            }
        }
    }

    cout<<"Edge\t\tWeight"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<"\t\t"<<G[i][parent[i]]<<endl;
    }

}

int main(){
    vector<vector<int>>G={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
    int V=G.size();//no of vertex
    cout<<V<<endl;
    prim_MST(G,V);
    return 0;
}