#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    int ans,curr;
    ans=curr=2;
    int prev_dif=arr[1]-arr[0];
    int j=2;
    while(j<n){
        if(prev_dif==arr[j]-arr[j-1]){
            curr++;
        }else{
            prev_dif=arr[j]-arr[j-1];
            curr=2;
        }
        j++;
        ans=max(ans,curr);
    }
    cout<<ans<<endl;
    return 0;
    
}
