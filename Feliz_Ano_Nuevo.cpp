#include<bits/stdc++.h>
using namespace std;

void print(string str,int n){
    for(int i=0;i<n;i++){
        cout<<str<<endl;
    }
}

int main(){
    string N;
    int n;
    cin>>N>>n;
    if(N=="N"){
        print("Feliz Ano Nuevo",n);
    }else{
        print("Happy New Year",n);
    }

    return 0;
}