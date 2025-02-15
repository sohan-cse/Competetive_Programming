#include<bits/stdc++.h>
using namespace std;

int findfact(int p){
        if(p==1)return 1;
        return p+findfact(p-1);
    }
void insert(int n){
    
    
    cout<<n;
    int fact_n=findfact(n);
    
}
int main(){
    vector<int>dir={-1,0,1,0,-1};
    int ct=0;
    for (int k = 0; k < 4; k++) {
                int row = 1 + dir[k];
                int col = 1 + dir[k + 1];
                //if(newR>=0&&newCol>=0)
                cout << "Neighbor " << ct << ": (" << row << ", " << col << ")\n";
            }
    int n=1<<2;
    cout<<"1<<2 :"<<n;
    insert(n);
}