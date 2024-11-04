#include<bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
    int temp,max;
    temp=max=a>b?a:b;
    do{
        if(max%a==0&&max%b==0){
            break;
        }else{
            max+=temp;
        }
    }while(true);
    return max;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    int a,b;
    a=arr[0];
    for(int i=1;i<n;i++){
        b=arr[i];
        a=lcm(a,b);
    }

    cout<<a<<endl;
}