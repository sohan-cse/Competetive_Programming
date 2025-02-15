#include <bits/stdc++.h>
using namespace std;

void ans(uint64_t A, uint64_t B, uint64_t G) {
    while (B % A == 0 && B > A && A != G) {
        if (B < G) break; // Prevent underflow
        B -= G;
    }
    if ((B != A && A >= G) || (B == A && B == G)) {
        cout << A << " " << B << endl;
    } else {
        cout << -1 << " " << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        uint64_t l, r, G;
        cin >> l >> r >> G;

        uint64_t A, B;

        if (l % G == 0) {
            A = l;
        } else {
            A = l + G - l % G; // Next multiple of G
        }

        B = (r / G) * G; // Largest multiple of G <= r

        ans(A, B, G);
    }
    return 0;
}
