#include<iostream>
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
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
}