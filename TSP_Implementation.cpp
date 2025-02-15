#include <bits/stdc++.h>
using namespace std;

int V;
vector<vector<int>> dist;
vector<vector<int>> dp;

int TSP_DP(int mask, int pos) {

    if (mask == (1 << V) - 1) return dist[pos][0];  // ✅ Return distance to starting city
    if (dp[mask][pos] != -1) return dp[mask][pos]; // ✅ Memoization check

    int ans = INT_MAX; // ✅ Removed global variable
    for (int city = 0; city < V; city++) {
        if (!(mask & (1 << city))) { // If city is not visited
            int newAns = dist[pos][city] + TSP_DP(mask | (1 << city), city);
            cout<<"newAns : "<<newAns<<endl;
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans; // ✅ Store in DP table
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    int src, wt, dest;
    dist.resize(V, vector<int>(V, 0)); // ✅ Initialize with INF
    dp.resize(1 << V, vector<int>(V, -1));  // ✅ Initialize DP table

    cout << "Enter edges (Enter -1 to stop):\n";
    while (true) {
        cin >> src;
        if (src == -1) break;  // ✅ Allow user to stop input
        cin >> wt >> dest;

        dist[src][dest] = wt;
        dist[dest][src] = wt;  // ✅ Ensure bidirectional edges
    }

    cout << "Minimum cost: " << TSP_DP(1, 0) << endl;
}
