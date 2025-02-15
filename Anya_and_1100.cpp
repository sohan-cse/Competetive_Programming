#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    int q;
    cin>>q;
    while(q--){
        int i;
        char v;
        cin>>i>>v;
        str[i-1]=v;
        bool isFound=(str.find("1100")!=string ::npos);
        //bool found = (text.find(word) != std::string::npos);
        if(isFound)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}