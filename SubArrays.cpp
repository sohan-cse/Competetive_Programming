#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr){
    vector<vector<int>>LIST;
    vector<int>subArr;
    vector<int>subArrSum;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            for(int k=i;k<=j;k++){
                subArr.push_back(arr[k]);
                //cout<<arr[k]<<" ";
            }
            //cout<<endl;
            LIST.push_back(subArr);
            subArr.clear();
        }
    }
    for(auto v:LIST){
        for(auto ele:v){
            cout<<ele<<" ";
        }
        subArrSum.push_back(accumulate(v.begin(),v.end(),0));
        cout<<endl;
    }
    sort(subArrSum.begin(),subArrSum.end());
    cout<<subArrSum.back()<<endl;
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