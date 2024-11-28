#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = true;
        for (auto child : adj[node]) {
            if (vis[child]) continue;
            dfs(child, adj, vis, st);
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>>& adj2, vector<int>& vis) {
        vis[node] = true;
        for (auto child : adj2[node]) {
            if (vis[child]) continue;
            dfs2(child, adj2, vis);
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        // Step 1: Perform DFS and store vertices in stack according to finish time
        vector<int> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> adj2(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adj2[it].push_back(i);
            }
        }

        // Step 3: Perform DFS on the reversed graph in the order of the stack
        fill(vis.begin(), vis.end(), false);
        int scc = 0; // Count of strongly connected components
        while (!st.empty()) {
            int top = st.top();
            cout<<"First top element "<<top<<endl;
            st.pop();
            if (!vis[top]) {
                scc++;
                dfs2(top, adj2, vis);
            }
        }

        return scc;
    }
};

int main() {
    int n, e;
    cin >> n >> e; // Number of vertices and edges
    vector<vector<int>> adjList(n);
    for (int i = 0; i < e; i++) {
        int src, des;
        cin >> src >> des; // Directed edge from src to des
        adjList[src].push_back(des);
    }

    Solution sol;
    int ans = sol.kosaraju(n, adjList);
    cout << ans;
    return 0;
}
