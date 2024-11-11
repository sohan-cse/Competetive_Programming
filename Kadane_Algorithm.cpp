#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr,int n){
    int currentSum=0;
    int mxSum=INT_MIN;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum<0){
            currentSum=0;
        }
        mxSum=max(mxSum,currentSum);
    }
    cout<<mxSum<<endl;
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