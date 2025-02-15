#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int ans=1;
    int p=3,ct=1;
    for(int i=0;ans<n;++i)
    {
        ans+=p;
        p*=2;
        ct++;
    }
    cout<<ct<<endl;
    return;
}

int main()
{
int testcase;
cin>>testcase;
while(testcase--)
{

solve();

}
return 0;
}