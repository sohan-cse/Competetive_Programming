#include<bits/stdc++.h>
using  namespace std;

int main(){
    string str;
    cin>>str;
    cout<<"Input string : "<<str<<endl;

    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<"After transform to Upper case: "<<str<<endl;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<"After transform to Lower case: "<<str<<endl;


}