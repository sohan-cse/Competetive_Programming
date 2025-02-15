#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b="";
        cin>>a;
        int a_size=a.size();
        for(int i=a_size-1;i>=0;i--){
            if(a[i]=='p')
                b+='q';
            else if(a[i]=='q')
                b+='p';
            else 
                b+=a[i];
        }
        cout<<b<<endl;

    }
}