#include<bits/stdc++.h>
using namespace std;
int ct=0;
int fib(int n,vector<int>&memo){
    ct++;
    if(memo[n]!=-1){
        return memo[n];
    }
    if(n<=1){
        return memo[n]=n;
    }
    return memo[n]=fib(n-1,memo)+fib(n-2,memo);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        ele=-1;
    }
    for(int i=0;i<n;i++){
        cout<<fib(i,arr)<<"  ";
    }
    cout<<endl<<ct<<endl;

    return 0;
}