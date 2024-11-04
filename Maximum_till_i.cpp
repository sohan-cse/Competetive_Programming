#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr,int n){
    int mx=INT_MIN;
    cout<<"Maximum="<<mx<<endl;
    for(int i=0;i<n;i++){
        cout<<(mx=max(mx,arr[i]))<<endl;
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