#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr){
    vector<int>subArrSumList;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            subArrSumList.push_back(sum);
        }
    }
    sort(subArrSumList.begin(),subArrSumList.end());
    cout<<subArrSumList.back()<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    solve(arr);
}