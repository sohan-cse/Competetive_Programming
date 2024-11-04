#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=2*n;
        vector<int>v(a);
        for(auto &ele:v){
            cin>>ele;
        }
       int count_1=count(v.begin(),v.end(),1);
       int count_0=2*n-count_1;
       if(count_0>=count_1)
       {
        cout<<count_1%2<<" "<<count_1<<endl;
       }
       else if(count_0==n||count_1==n){
        cout<<0<<" "<<0<<endl;
       }
       else if(count_1>count_0){
        cout<<count_1% 2<<" "<<count_0<<endl;
       }
       
    }
}