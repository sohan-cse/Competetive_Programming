#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    int a,b;
    a=arr[0];
    for(int i=1;i<n;i++){
        b=arr[i];
        a=gcd(a,b);
    }
    cout<<a<<endl;
}