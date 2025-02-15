#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr(m,vector<int>(n));
    for(auto &vec: arr){
        for(auto &ele:vec){
            cin>>ele;
        }
    }
    cout<<"Matrix is: "<<endl;
    for(auto vec: arr){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Spiral matrix : "<<endl;
    int start_row=0,end_row=m-1,start_col=0,end_col=n-1;
    while(start_row<=end_row&&start_col<=end_col){
        for(int col=start_col;col<=end_col;col++){
            cout<<arr[start_row][col]<<" ";
        }
        cout<<endl;
        start_row++;
        for(int row=start_row;row<=end_row;row++){
            cout<<arr[row][end_col]<<" ";
        }
        cout<<endl;
        end_col--;
        for(int col=end_col;col>=start_col;col--){
            cout<<arr[end_row][col]<<" ";
        }
        cout<<endl;
        end_row--;
        for(int row=end_row;row>=start_row;row--){
            cout<<arr[row][start_col]<<" ";
        }
        cout<<endl;
        start_col++;
    }
}