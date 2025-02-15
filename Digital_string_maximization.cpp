#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int p=0,q=1;
        while(q<str.size()){
            if(str[q]-str[p]>1){
                str[q]--;
                swap(str[q],str[p]);
                if(p>0){
                    p--;
                    q--;
                }
            }else{
                p++;
                q++;
            }
            
        }
        cout<<str<<endl;
    }
}