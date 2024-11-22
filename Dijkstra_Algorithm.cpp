#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>dijkstra(int v,vector<pair<int,int>>g[],int s){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>disArr(v,1e9);

    disArr[s]=0;
    pq.push({s,0});

    while(!pq.empty()){
        int node=pq.top().first;
        int dis=pq.top().second;
        pq.pop();

        for(auto pair_d_w : g[node]){

            int d_Node=pair_d_w.first;
            int d_edgeWeight=pair_d_w.second;

            if(dis+d_edgeWeight<disArr[d_Node]){
                disArr[d_Node]=dis+d_edgeWeight;
                pq.push({d_Node,disArr[d_Node]});
               
            }
        }
       
    }
    cout<<"Size of pririty queue : "<<pq.size();
    return disArr;
}
int main(){
    vector<pair<int,int>>g[N];
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        g[s].push_back({d,w});
        g[d].push_back({s,w});
    }
    vector<int>dis=dijkstra(n,g,0);
    for(int i=0;i<n;i++){
        cout<<"Distance from 0 to "<<i<<" is : "<<dis[i]<<endl;
    }
}