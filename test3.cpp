#include<bits/stdc++.h>
using namespace std;
void print(int arr[]){
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"  ";
    }
}
change(int arr[]){
    swap(arr[1],arr[2]);
}
void ab_swap(int *c,int *d){
    cout<<"c="<<c<<" "<<"d="<<d<<endl;
    cout<<"*c="<<*c<<" "<<"*d="<<*d<<endl;
    swap(*c,*d);
}
int main(){
    // vector<int>nums={1,2,2,2,2,2};
    // int ones=0,twos=0;
    // for(auto&ele:nums){
    // twos=twos|ones&ele;
    // cout<<"Twos : "<<twos<<endl;
    // ones=ones^ele;
    // cout<<"Ones : "<<ones<<endl;
    // int threes=ones&twos;
    // cout<<"Threes: "<<threes<<endl;
    // ones=ones&~threes;
    // cout<<"ones&~threes: "<<ones<<endl;
    // twos=twos&~threes;
    // cout<<"twos&~threes: "<<twos<<endl;
    // }

    // cout<<(15&~7)<<endl;
    int arr[]={10,2,3,4,5};
    int arr2[][2]={{10,2},{3,4},{5,6}};
    print(arr);
    change(arr);
    print(arr);
    int a=10,b=20;
    cout<<"a="<<a<<" "<<"b="<<b<<endl;
    ab_swap(&a,&b);
    cout<<"a="<<a<<" "<<"b="<<b<<endl;
    cout<<"a="<<&a<<" "<<"b="<<&b<<endl;
    cout<<"*arr="<<*(arr+2)<<endl;
    cout<<"*arr2="<<*(*arr2+1)<<endl;
}