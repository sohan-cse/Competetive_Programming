#include<bits/stdc++.h>
using namespace std;
int ct=0;
int fib(int n){
    ct++;
    if(n==0)return 0;
    if(n==1|| n==2)return 1;
    return fib(n-1)+fib(n-2);

}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<fib(i)<<"  ";
    }

    cout<<"\nFunction call : "<<ct<<endl;

    return 0;
}