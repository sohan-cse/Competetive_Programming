// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;

// int parent[N];
// int Size[N];

// void Make(int v){
//     parent[v]=v;
//     Size[v]=1;
// }

// int Find(int v){
//     if(v==parent[v])return v;
//     return parent[v]=Find(parent[v]);
// }

// void Union(int u,int v ){
//     u=Find(u);
//     v=Find(v);

//     if(u!=v){
//         if(Size[u]<Size[v]){
//             swap(u,v);
//         }
//         parent[v]=u;
//         Size[u]+=Size[v];
//     }
// }

// int main(){
//     int V,E;
//     cout<<"Enter no of vertex and edges :"<<endl;
//     cin>>V>>E;
//     for(int i=1;i<=V;i++){
//         Make(i);
//     }
//     vector<pair<int,pair<int,int>>>edges;
//     while(E--){
//         int wt,u,v;
//         cout<<"Enter weight , source and destination : ";
//         cin>>wt>>u>>v;
//         edges.push_back({wt,{u,v}});
//     }
//     sort(edges.begin(),edges.end());

//     int wt_ct=0;
//     for(auto&edge:edges){
//         int wt=edge.first;
//         int u=edge.second.first;
//         int v=edge.second.second;
//         if(Find(u)==Find(v))continue;
//         Union(u,v);
//         cout<<u<<"--->"<<v<<endl;
//         wt_ct+=wt;
//     }
//     cout<<"Total cost : "<<wt_ct<<endl;
// }


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N], Size[N];

void Make(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int Find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]); // Path compression
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        if (Size[u] < Size[v]) swap(u, v);
        parent[v] = u;
        Size[u] += Size[v];
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        Make(i);
    }

    vector<pair<int, pair<int, int>>> edges; // Fixed bracket issue

    while (E--) {
        int wt, u, v;
        cout << "Enter weight, source, and destination: ";
        cin >> wt >> u >> v;
        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end()); // Fixed sorting issue

    int wt_ct = 0;
    cout << "Edges in MST:\n";
    for (auto& edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (Find(u) == Find(v)) continue; // Avoid cycle

        Union(u, v);
        cout << u << " ---> " << v << " (Weight: " << wt << ")\n";
        wt_ct += wt;
    }

    cout << "Total cost of MST: " << wt_ct << endl;
    return 0;
}
