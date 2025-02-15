#include <bits/stdc++.h>
using namespace std;

void Divisible(string N) {
    int odd = 0, even = 0;

    for (int i = 0; i < N.size(); ++i) {
        if ((i+1) % 2 == 0) {
            even += int(N[i] - '0');
        } else {
            odd += int(N[i] - '0');
        }
    }

    int result = abs(odd - even);

    if (result % 11 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string N;
        cin >> N;
        Divisible(N);
    }
    return 0;
}
