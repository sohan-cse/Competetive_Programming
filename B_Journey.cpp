#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int ct=0;
        ct=(n/(a+b+c));
        n=n-ct*(a+b+c);
        ct*=3;
            if(n>0){
                n-=a;
                ct++;
            }
            if(n>0){
                n-=b;
                ct++;
            }
            if(n>0){
                n-=b;
                ct++;
            }
        cout<<ct<<endl;
    }
}