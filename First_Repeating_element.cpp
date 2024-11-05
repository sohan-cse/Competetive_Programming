#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    vector<int>idx(N,-1);
    int minIdx=INT_MAX;
    for(int i=0;i<n;i++){
        if(idx[arr[i]]==-1){
            idx[arr[i]]=i;
        }else{
            minIdx=min(minIdx,idx[arr[i]]);
        }
    }
    if(minIdx==INT_MAX){
        cout<<"-1"<<endl;
    }else{
        cout<<minIdx+1<<endl;
    }
}