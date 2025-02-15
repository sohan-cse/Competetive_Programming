#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        int ct=0;
        int i=0,j=0,k=0;
        int n=c.size();
        while(k<n){

            while(i<=k){
                    if(a[i]==c[k] && i<a.size()){
                    i++;
                    k++;
                    continue;
                }
                break;
            }
            while(j<=k){
                    if(b[j]==c[k] && j<b.size()){
                    j++;
                    k++;
                    continue;
                }
                break;
            }


            // if (i>=a.size()){
            //     if(b[++j]==c[k]){
            //         k++;
            //         continue;
            //     }else{
            //         k++;
            //         ct++;
            //         continue;
            //     }
            // }
            // if (j>=b.size()){
            //     if(b[++i]==c[k]){
            //         k++;
            //         continue;
            //     }else{
            //         k++;
            //         ct++;
            //         continue;
            //     }
            // }
            if(a[i]==c[k] && i<a.size()){
                i++;
                k++;
                continue;
            }
            if(b[j]==c[k] && j<b.size()){
                j++;
                k++;
                continue;
            }
            ct++;
            k++;
        }
        cout<<ct<<endl;
    }
}