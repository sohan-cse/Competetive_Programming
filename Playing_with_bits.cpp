#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=7;i>=0;i--){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

int main(){
    printBinary(9);
    int a=9;
    int i=1;
    if((a&(1<<i))!=0){
        cout<<"bit is set"<<endl;
    }else{
        cout<<"bit is not set"<<endl;
    }
    //set 1 bit
    cout<<"set 1 bit"<<endl;
    printBinary(a|(1<<1));
    //set 2 bit
    cout<<"set 2 bit"<<endl;
    printBinary(a|(1<<2));
    //unset 3 bit
    cout<<"unset 3 bit"<<endl;
    printBinary(a&~(1<<3));
    //toggle(0-->1 || 1-->0) 0 bit
    cout<<"toggle(0-->1 || 1-->0) 0 bit"<<endl;
    printBinary(a^(1<<0));
    //toggle 3 bit
    cout<<"toggle 3 bit"<<endl;
    printBinary(a^(1<<3));
    //toggle 0 & 3 bit
    cout<<"toggle 0 & 3 bit"<<endl;
    printBinary((a^(1<<3))^(1<<0));

    //bit count
    a=15;
    int ct=0;
    for(int i=31;i>=0;--i){
        ct+=(1&(a>>i));
    }
    cout<<"bits : "<<ct<<endl;
    //bit count
    a=31;
    ct=0;
    for(int i=31;i>=0;--i){
        if((a&(1<<i))!=0)ct++;
    }
    cout<<"bits : "<<ct<<endl;
    //bit count
    a=63;
    cout<<"bits : "<<__builtin_popcount(a)<<endl;
    cout<<"bits : "<<__builtin_popcountll((1LL<<35)-1)<<endl;

    return 0;
}