#include<bits/stdc++.h>
using namespace std;

void Conversion(long long N,long long K){
    string result="";
    while (N)
    {
        result=char((N%K)+'0')+result;
        N/=K;
    }

    cout<<result<<endl;   
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long N,K;
        cin>>N>>K;
        Conversion(N,K);
    }
    return 0;
}