#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<pair<int, int>> graph[n];

        for (auto& vec : edges) {
            int src = vec[0];
            int des = vec[1];
            int t = vec[2];
            graph[src].push_back({des, t});
            graph[des].push_back({src, t});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<int> fees(n, INT_MAX);
        vector<int> times(n, INT_MAX);

        fees[0] = passingFees[0];
        times[0] = 0;
        pq.push({ passingFees[0],0, 0});  // {time, fee, node}

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            // Extract tuple elements using get<>
            int s_fee = get<0>(top);  // Changed the order as per your request
            int s_time = get<1>(top);
            int u = get<2>(top);

            if (s_time > times[u]) continue;

            for (auto& edge : graph[u]) {
                int v = edge.first;
                int d_time = edge.second;

                if (s_time + d_time <= maxTime) {
                    if (s_time + d_time < times[v] || s_fee + passingFees[v] < fees[v]) {
                        if(s_time + d_time < times[v])
                        times[v] = s_time + d_time;
                        if(s_fee + passingFees[v] < fees[v])
                        fees[v] = s_fee + passingFees[v];
                        pq.push({fees[v],times[v],  v});
                    }
                }
            }
        }

        return fees[n - 1] == INT_MAX ? -1 : fees[n - 1];
    }
};




int main() {
    int row;
    cout<<"Enter edges size :";
    cin >> row;
    vector<vector<int>> edges(row, vector<int>(3));
    for (auto& r : edges) {
        for (auto& ele : r) {
            cin >> ele;
        }
    }
    cout<<"Enter maxtime :";
    int maxTime;
    cin >> maxTime;
    cout<<"Enter nodes number :";
    int n;
    cin >> n;
    vector<int> passingFees(n);
    cout<<"Enter passing fees of every node :";
    for (int i = 0; i < n; i++) {
        cin >> passingFees[i];
    }
    
    Solution sol;
    int ans = sol.minTime(maxTime, edges, passingFees);
    cout << ans;
    return 0;
}
