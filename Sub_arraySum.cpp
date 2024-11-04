#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<endl;
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