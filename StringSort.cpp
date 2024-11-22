#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    cout<<"Before sorting : "<<str<<endl;
    sort(str.begin(),str.end(),greater<int>());
    cout<<"After sorting decending order : "<<str<<endl;
    sort(str.begin(),str.end());
    cout<<"After sorting i ascending order :"<<str<<endl;
}