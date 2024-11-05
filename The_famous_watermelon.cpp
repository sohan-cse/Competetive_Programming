#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{

    string num;
    cin>>num;
    int sum=0;
    for(char dig:num){
        sum+=dig-'0';
    }
    if(sum%3==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
return 0;
}