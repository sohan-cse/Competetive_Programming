#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    vector<int>jumps(n,1e9);
    jumps[0]=0;
    for(int i=0;i<n;i++){
        for(int j=k;j<i;j++){
            if(i<=j+arr[j]){
                jumps[i]=min(jumps[i],jumps[j]+1);
            }
        }
    }
    cout<<"\ncount"<<ct<<"\nJumps : ";
    for(auto&ele:jumps){
        cout<<ele<<" ";
    }
 
}