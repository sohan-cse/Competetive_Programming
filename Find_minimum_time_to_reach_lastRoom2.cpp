#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(vector<vector<int>>& moveTime) {
        int row = moveTime.size();
        int col = moveTime[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<int> dir = {-1, 0, 1, 0, -1};

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            tuple<int, int, int> topElement = pq.top();
            int present_time = get<0>(topElement);
            int present_row = get<1>(topElement);
            int present_col = get<2>(topElement);

            pq.pop();

            if (visited[present_row][present_col]) continue;
            visited[present_row][present_col] = true;

            if (present_row == row - 1 && present_col == col - 1) {
                return present_time;
            }

            for (int i = 0; i < 4; i++) {
                int newRow = present_row + dir[i];
                int newCol = present_col + dir[i + 1];

                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !visited[newRow][newCol]) {
                    int newTime;
                    if ((present_row + present_col) % 2 == 0) {
                        newTime = 1 + max(present_time, moveTime[newRow][newCol]);
                    } else {
                        newTime = 2 + max(present_time, moveTime[newRow][newCol]);
                    }
                    pq.push({newTime, newRow, newCol});
                }
            }
        }
        return -1;
    }
};

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> moveTime(row, vector<int>(col));
    for (auto& r : moveTime) {
        for (auto& ele : r) {
            cin >> ele;
        }
    }
    Solution solution;
    int time = solution.minTime(moveTime);
    cout << time << endl;
    return 0;
}
