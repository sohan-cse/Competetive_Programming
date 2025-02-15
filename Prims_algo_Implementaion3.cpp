#include<bits/stdc++.h>
using namespace std;

int Min_key(vector<bool>&vis,vector<int>&key,int &V){
    int minVtx,min_wt=INT_MAX;
    for(int vtx=0;vtx<V;vtx++){
        if(!vis[vtx]&&key[vtx]<min_wt){
            minVtx=vtx;
            min_wt=key[vtx];
        }
    }
    return minVtx;
}

void prims_MST(vector<vector<int>>&g,int &V){
    vector<int>parent(V,-1);
    vector<bool>vis(V,false);
    vector<int>key(V,INT_MAX);

    key[0]=0;
    //parent[0]=-1;

    for(int i=0;i<V-1;i++){
        int u=Min_key(vis,key,V);
        vis[u]=true;

        for(int v=0;v<V;v++){
            if(g[u][v]&&!vis[v]&&g[u][v]<key[v]){
                parent[v]=u;
                key[v]=g[u][v];
            }
        }
    }

    int total_wt_ct=0;
    for(int i=0;i<V;i++){
        if(parent[i]==-1)continue;
        cout<<parent[i]<<"-->"<<i<<"  weight : "<<g[parent[i]][i]<<endl;
        total_wt_ct+=g[parent[i]][i];

    }

    cout<<"Total weight cos of MST : "<<total_wt_ct<<endl;

}

// int min_KEY(vector<int>&key,vector<bool>&vis,int V){
//     int min=INT_MAX;
//     int minVtx;
//     for(int vtx=0;vtx<V;vtx++){
//         if(!vis[vtx] && key[vtx]<min){
//             min=key[vtx];
//             minVtx=vtx;
//         }
//     }
//     return minVtx;
// }

// void prims_MST(vector<vector<int>>&G,int V){
//     vector<int>parent(V,-1);
//     vector<int>key(V,INT_MAX);
//     vector<bool>vis(V,false);

//     key[0]=0;
//     parent[0]=-1;//starting  vertex

//     for(int i=0;i<V-1;i++){
//         int u=min_KEY(key,vis,V);
//         vis[u]=true;

//         for(int v=0;v<V;v++){
//             if(G[u][v]&&!vis[v]&&G[u][v]<key[v]){
//                 parent[v]=u;
//                 key[v]=G[u][v];
//             }
//         }
//     }

//     cout<<"Edge\t\tWeight"<<endl;
//     for(int i=1;i<V;i++){
//         cout<<parent[i]<<" - "<<i<<"\t\t"<<G[i][parent[i]]<<endl;
//     }

// }

int main(){
    int V,E;
    cout<<"Enter no of vertices & edges : ";
    cin>>V>>E;

    vector<vector<int>>G(V,vector<int>(V,0));

    for(int i=0;i<E;i++){
        int u, v, wt;
        cout<<"Source , destination ,weight : ";
        cin>>u>>v>>wt;
        G[u][v]=wt;
        G[v][u]=wt;
    }

    prims_MST(G,V);

    return 0;
}