#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
void dfs(int par,vector<int>g[]){

    vis[par]=true;
    cout<<par<<" ";
    for(auto child:g[par]){
        if(vis[child])continue;
        dfs(child,g);
    }

}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int>g[n+1];
    for(int i=0;i<e;i++){
        int src,dest;
        cin>>src>>dest;
        g[src].push_back(dest);
        g[dest].push_back(src);
    }
    int strt;
    cout<<"Enter source to start : ";
    cin>>strt;
    dfs(strt,g);
}