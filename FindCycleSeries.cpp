// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int findCycle(int i,int j, vector<vector<int>>&arr,vector<int>target){
//         vector<int>dir={0,-1,0,1,0};
//         int m=arr.size();
//         int n=arr[0].size();
//         vector<vector<bool>>vis(m,vector<bool>(n,false));
//         queue<pair<int,int>>q;
//         q.push({i,j});
//         int ptr=0;
//         int ct=0;
//         while(!q.empty()){
//             pair<int,int>curr_ele=q.front();
//             q.pop();
//             int row=curr_ele.first;
//             int col=curr_ele.second;
//             vis[row][col]=true;

//             for(int k=0;k<4;k++){
//                 int newR=row+dir[k];
//                 int newC=col+dir[k+1];

//                 if((newR>=0&&newC>=0&&newR<m&&newC<n)&&!vis[newR][newC]){
//                     if(arr[newR][newC]==target[ptr]){
//                         q.push({newR,newC});
//                         vis[newR][newC]=true;
//                         ptr++;
//                         if(newC<col){
//                             for(int colIdx=0;colIdx<n;colIdx++){
//                                 vis[newR+1][colIdx]=true;
//                             }
//                         }else if(newC>col){
//                             for(int colIdx=0;colIdx<n;colIdx++){
//                                 vis[newR-1][colIdx]=true;
//                             }
//                         }else if(newR<row){
//                             for(int rowIdx=0;rowIdx<m;rowIdx++){
//                                 vis[rowIdx][newC-1]=true;
//                             }
//                         }else if(newR>row){
//                             for(int rowIdx=0;rowIdx<m;rowIdx++){
//                                 vis[rowIdx][newC+1]=true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         if(ptr==3){
//             ct++;
//         }
//         return ct;

//     }
    
// };
// int main(){
//     Solution sol;
//     int m,n;
//     cin>>m>>n;
//     vector<vector<int>>arr(m,vector<int>(n));
//     for(auto&row:arr){
//         for(auto&ele:row){
//             cin>>ele;
//         }
//     }
//     vector<int>target={5,4,3};
//     int cycle=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(arr[i][j]!=1)continue;
//             cycle+=sol.findCycle(i,j,arr,target);
//         }
//     }
//     cout<<cycle<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSequence(int i, int j, vector<vector<int>>& arr, vector<int>& target) {
        vector<int> dir = {0, -1, 0, 1, 0}; // Directions for movement (left, up, right, down)
        int m = arr.size();
        int n = arr[0].size();
        int targetSize = target.size();
        vector<vector<bool>> vis(m, vector<bool>(n, false)); // Visited array
        queue<pair<pair<int, int>, int>> q; // Queue stores (row, col, targetIndex)
        
        q.push({{i, j}, 0}); // Start BFS from (i, j) with target index 0
        
        while (!q.empty()) {
            pair<pair<int, int>, int>curr=q.front();
            pair<int, int>cell=curr.first;
            int ptr = curr.second;
            int row = cell.first, col = cell.second;
            q.pop();

            if (ptr == targetSize - 1 && arr[row][col] == target[ptr]) {
                return 1; // Found the full sequence
            }

            for (int k = 0; k < 4; k++) {
                int newR = row + dir[k];
                int newC = col + dir[k + 1];
                int nextPtr = ptr + 1;

                // Check boundaries, visited status, and match with the next target value
                if (newR >= 0 && newC >= 0 && newR < m && newC < n &&
                    !vis[newR][newC] && nextPtr < targetSize &&
                    arr[newR][newC] == target[nextPtr]) {
                    vis[newR][newC] = true; // Mark as visited
                    q.push({{newR, newC}, nextPtr});
                }
            }
        }
        return 0; // Sequence not found
    }
};

int main() {
    Solution sol;
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n));
        for (auto& row : arr) {
            for (auto& ele : row) {
                cin >> ele;
            }
        }

        vector<int> target = {1, 5, 4, 3}; // Target sequence to find
        int sequenceCount = 0;

        // Iterate through the grid to start BFS from cells containing `1`
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == target[0]) { // Start only if the cell matches the first target value
                    sequenceCount += sol.findSequence(i, j, arr, target);
                }
            }
        }

        cout << sequenceCount << endl; // Output the count of sequences found
    }
    return 0;
}
