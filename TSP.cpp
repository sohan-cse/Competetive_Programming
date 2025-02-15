// #include<bits/stdc++.h>
// using namespace std;
// int V;
// vector<vector<int>>dist;
// vector<vector<int>>dp;
// vector<vector<int>>parent;

// int TSP(int mask,int pos,int strt){

//     if(mask==((1<<V)-1))return dist[pos][strt];
//     if(dp[mask][pos]!=-1)return dp[mask][pos];

//     int ans=INT_MAX;
//     int bestCity=-1;

//     for(int city=0;city<V;city++){
//         if(!(mask&(1<<city))){
//             int newAns=dist[pos][city]+TSP(mask|(1<<city),city,strt);
//             if(ans>newAns){
//                 ans=newAns;
//                 bestCity=city;
//             }
//         }
//     }
//     parent[mask][pos]=bestCity;
//     dp[mask][pos]=ans;
//     cout<<"dp[mask][pos]: "<<dp[mask][pos]<<endl;
//     return ans;
// }

// void getPath(int mask,int pos,int strt){
//     vector<int>path;
//    // int mask=1,pos=0;
//     while(true){
//         path.push_back(pos);
//         int nextCity=parent[mask][pos];
//         if(nextCity==-1)break;
//         mask|=1<<nextCity;
//         pos=nextCity;
//     }
//     path.push_back(strt);
//     cout<<"Path : ";
//     for(auto&p:path)cout<<p<<" ";
// }

// int main(){

//     cout<<"Enter number of vertices : "<<endl;
//     cin>>V;

//     dist.resize(V,vector<int>(V,0));
//     dp.resize(1<<V,vector<int>(V,-1));
//     parent.resize(1<<V,vector<int>(V,-1));

//     cout<<"Enter edges (src= -1 for break) : "<<endl;
//     while(true){
//         int src,wt,dest;
//         cout<<"Src : ";
//         cin>>src;
//         if(src==-1)break;
//         cout<<"wt  dest"<<endl;
//         cin>>wt>>dest;
//         dist[src][dest]=wt;
//         dist[dest][src]=wt;
//     }

//     cout<<"Enter starting vertex : ";
//     int strt;cin>>strt;

//     cout<<"Minimum cost : "<<TSP(1<<strt,strt,strt)<<endl;
//     getPath(1<<strt,strt,strt);

// }

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  // Large value to represent infinity
int V;
vector<vector<int>> dist;
vector<vector<int>> dp;
vector<vector<int>> parent;

int TSP(int mask, int pos, int strt) {
    if (mask == ((1 << V) - 1)) return dist[pos][strt];  // Base case: all cities visited
    if (dp[mask][pos] != -1) return dp[mask][pos];       // Memoized case

    int ans = INF;
    int bestCity = -1;

    for (int city = 0; city < V; city++) {
        if (!(mask & (1 << city)) && dist[pos][city] != INF) {  // Ensure valid edge
            int newAns = dist[pos][city] + TSP(mask | (1 << city), city, strt);
            if (ans > newAns) {
                ans = newAns;
                bestCity = city;
            }
        }
    }

    parent[mask][pos] = bestCity;
    return dp[mask][pos] = ans;
}

void getPath(int mask, int pos, int strt) {
    vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        int nextCity = parent[mask][pos];
        if (nextCity == -1) break;
        mask ^= (1 << pos);  // Unset the current city in the mask
        pos = nextCity;
    }
    path.push_back(strt);  // Add the starting city

    cout << "Path : ";
    for (auto &p : path) cout << p << " ";
    cout << endl;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    dist.resize(V, vector<int>(V, INF));  // Initialize with INF
    dp.resize(1 << V, vector<int>(V, -1));
    parent.resize(1 << V, vector<int>(V, -1));

    for (int i = 0; i < V; i++) dist[i][i] = 0;  // Distance from a city to itself is 0

    cout << "Enter edges (src = -1 to stop): " << endl;
    while (true) {
        int src, wt, dest;
        cout << "Src: ";
        cin >> src;
        if (src == -1) break;
        cout << "Weight & Destination: ";
        cin >> wt >> dest;
        dist[src][dest] = wt;
        dist[dest][src] = wt;
    }

    cout << "Enter starting vertex: ";
    int strt;
    cin >> strt;

    cout << "Minimum cost: " << TSP(1 << strt, strt, strt) << endl;
    getPath(1 << strt, strt, strt);

    return 0;
}
