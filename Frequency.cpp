#include<bits/stdc++.h>
using namespace  std;

int main(){

    string str;
    getline(cin,str);

    vector<int>freq(26);

    for(int&i:freq){
        i=0;
    }

    for(int i=0;i<str.size();i++){
        freq[str[i]-'a']++;
    }

    int mxElement=*max_element(freq.begin(),freq.end());

    cout<<mxElement<<endl;
    cout<<char('a'+find(freq.begin(),freq.end(),mxElement)-freq.begin());
    
    return 0;
}