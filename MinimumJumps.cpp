#include <bits/stdc++.h>
using namespace std;

void MinimumJumps(vector<int>& arr) {
    int n = arr.size();
    
    // Edge cases
    if (n == 1) {
        cout << 0 << endl; // Already at the end
        return;
    }
    if (arr[0] == 0) {
        cout << -1 << endl; // Cannot move anywhere
        return;
    }

    int jumps = 0;
    int l = 0, r = 0, farthest = 0;

    while (r < n - 1) {
        for (int i = l; i <= r; i++) {
            farthest = max(farthest, i + arr[i]);
        }
        if (farthest <= r) { // Cannot move further
            cout << -1 << endl;
            return;
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }

    cout << jumps << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& ele : arr) {
        cin >> ele;
    }
    MinimumJumps(arr);
}
