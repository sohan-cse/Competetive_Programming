#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>Matrix(m,vector<int>(n));
    for(auto&row:Matrix){
        for(auto&ele:row){
            cin>>ele;
        }
    }
    cout<<"Matrix is : "<<endl;
    for(auto&row:Matrix){
        for(auto&ele:row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    int target;
    cin>>target;
    int row=0,col=n-1;
    bool flag=false;
    int ct=0;
    while(row<m&&col>=0){
        ct++;
        if(Matrix[row][col]==target){
            flag =true;
            break;
        }
        if(Matrix[row][col]<target)row++;
        else if(Matrix[row][col]>target)col--;
    }
    if(flag){
        cout<<"Element is found"<<endl<<ct;
    }else{
        cout<<"Element is not found"<<endl<<ct;
    }

    return 0;
}