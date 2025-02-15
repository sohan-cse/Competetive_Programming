#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dist;
vector<vector<int>>dp;

int n;

int tspDP(int mask,int pos){
   // cout<<"Position : "<<pos<<endl;
    if(mask==(1<<n)-1)return dist[pos][0];

    if(dp[mask][pos]!=-1)return dist[mask][pos];

    int ans=INT_MAX;

    for(int city=0;city<n;city++){
        
        if(!(mask&(1<<city))){
            //cout<<"city: "<<city<<endl;
            cout<<"pos: "<<pos<<" city : "<<city<<endl;
            int newAns=dist[pos][city]+tspDP(mask|(1<<city),city);
            //cout<<"New ans : "<<newAns<<endl;
            ans=min(ans,newAns);
            //cout<<"ans: "<<ans<<endl;
        }
    }

     dp[mask][pos]=ans;
     cout<<" dp[mask][pos] : "<<dp[mask][pos]<<endl;
     return ans;
}

int main(){
    dist={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    n=dist.size();
    dp.resize(1<<n,vector<int>(n,-1));
    int minCost=tspDP(1,0);
    cout<<"Minimum cost : "<<minCost<<endl;

    return 0;
}