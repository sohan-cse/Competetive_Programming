#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int ans1=min(m,a);
        int ans2=min(m,b);
        int rem=2*m-ans1-ans2;
        int ans3=min(rem,c);
        cout<<ans1+ans2+ans3<<endl;
    }
}
