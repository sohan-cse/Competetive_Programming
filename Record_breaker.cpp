#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr,int n){
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(i==n-1&&arr[i]>mx){
            cout<<arr[i]<<endl;
        }
        else if(arr[i]>arr[i+1] && arr[i]>mx){
            cout<<arr[i]<<endl;
            mx=arr[i];
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    solve(arr,n);
}
