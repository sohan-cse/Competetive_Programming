#include<bits/stdc++.h>
using namespace std;

void solve()
{
int n,k;
cin>>n>>k;
vector<int>v(n);
for(int &num:v)
{
    cin>>num;
}

for(int i=0;i<n;++i)
{
    int ct=0;
    for(int j=0;j<n;++j)
    {
        if(i!=j)
        {
            int sum=abs(v[i]-v[j]);

            if(sum%k==0){
                break;
            }else ct++;    
        }
    }
    if(ct==n-1){
        cout<<"YES"<<endl<<i+1<<endl;
        return;
    }
}
cout<<"NO"<<endl;
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