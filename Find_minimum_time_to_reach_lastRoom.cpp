#include<bits/stdc++.h>
using namespace std;

int minTime(vector<vector<int>>moveTime){

     int m = moveTime.size();
        int n = moveTime[0].size();

        // Min-heap: stores tuples {time, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Directions for moving: up, right, down, left
        vector<int> dir = {-1, 0, 1, 0, -1};

        // Track visited nodes
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push starting point {time, row, col}
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            // Get the top element (minimum time)
            tuple<int,int,int>TopEle = pq.top();
             int time=get<0>(TopEle) ;
             int row=get<1>(TopEle) ;
             int col=get<2>(TopEle);
            pq.pop();

            // If this cell is already visited, skip
            if (visited[row][col]) continue;

            // Mark this cell as visited
            visited[row][col] = true;

            // Check if the target is reached
            if (row == m - 1 && col == n - 1) {
                return time; // Return the minimum time to reach the bottom-right corner
            }

            // Explore all 4 directions
            for (int k = 0; k < 4; k++) {
                int newR = row + dir[k];
                int newCol = col + dir[k + 1];

                // Check bounds and if not visited
                if (newR >= 0 && newCol >= 0 && newR < m && newCol < n && !visited[newR][newCol]) {
                    // Calculate the time for the new cell   
                    int newTime = 1 + max(time, moveTime[newR][newCol]);                  
                    pq.push({newTime, newR, newCol});
                }
            }
          
        }

        // If no path to the bottom-right exists
        return -1;
}

int main(){
    int m,n,weight;
    cin>>m>>n;
    vector<vector<int>>moveTime(m,vector<int>(n));
    for(auto &row:moveTime){
        for(auto &ele:row){
            cin>>ele;
        }
    }
    int time=minTime(moveTime);
    cout<<time<<endl;
      
    return 0;
}