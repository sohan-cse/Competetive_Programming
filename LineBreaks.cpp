#include<bits/stdc++.h>
using namespace std;
void solve(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        string str="";
        int ct=0;
        for(int i=1;i<=m;i++){
            string s;
            cin>>s;
            str+=s;
            if(str.size()<=n){
                ct++;
            }
        }
        cout<<ct<<endl;
    }
}
int main(){
    solve();
    return 0;
}