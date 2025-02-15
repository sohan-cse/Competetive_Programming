#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> dir = { -1, -1,-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0,-1}; 
    int ct = 0;

    for (int i = 0; i < 16; i += 2) { // Increment by 2 to handle row and column pairs
        ct++;
        int row = 1 + dir[i];     // Row offset
        int col = 1 + dir[i + 1]; // Column offset
        cout << "Neighbor " << ct << ": (" << row << ", " << col << ")\n";
    }
}