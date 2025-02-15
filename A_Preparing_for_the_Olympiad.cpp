#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(auto&ele:a){
            cin>>ele;
        }
        for(auto&ele:b){
            cin>>ele;
        }
        int i=0;
        int ans=0;
        while(i<n-1){
            if(a[i]>b[i+1]){
                ans+=a[i]-b[i+1];
            }
            i++;
        }
        ans+=a[i];
        
        cout<<ans<<endl;
        
    }
}