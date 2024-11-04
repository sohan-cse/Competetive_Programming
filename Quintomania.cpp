#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ans=true;
        vector<int>arr(n);
        for(auto&ele:arr){
            cin>>ele;
        }
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])!=5&&abs(arr[i]-arr[i+1])!=7){
                ans=false;
                break;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}