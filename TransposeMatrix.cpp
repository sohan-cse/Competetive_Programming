#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>Matrix(m,vector<int>(n));
    for(auto&row:Matrix){
        for(auto&ele:row){
            cin>>ele;
        }
    }
    cout<<"Matrix is : "<<endl;
    for(auto&row:Matrix){
        for(auto&ele:row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>>T_Matrix(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            T_Matrix[j][i]=Matrix[i][j];
        }
    }
    cout<<"T_Matrix is : "<<endl;
    for(auto&row:T_Matrix){
        for(auto&ele:row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}