#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numIslands(vector<vector<char>>&grid){

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0'||vis[i][j])continue;
                island(i,j,grid,vis);
                ct++;
            }
        }
        return ct;

    }
    void island(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
        vector<int>dir={-1,0,1,0,-1};
        while (!q.empty())
        {
            pair<int,int>current=q.front();
            q.pop();
            int current_R=current.first;
            int current_C=current.second;
            for (int k = 0; k<4; k++)
            {
                int newR=current_R+dir[k];
                int newC=current_C+dir[k+1];
                if((newR>=0&&newC>=0&&newR<m &&newC<n)&&!vis[newR][newC] && grid[newR][newC]=='1')
                {
                    vis[newR][newC]=true;
                    q.push({newR,newC});
                }
            }
            
        }
        
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>>grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    Solution sol;
    int ans =sol.numIslands(grid);
    cout<<ans<<endl;

    return 0;
}