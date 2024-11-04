#include<iostream>
using namespace std;
int lcm(int a,int b){
    int max=a>b?a:b;
    int temp=max;
    do{
        if(max%a==0&&max%b==0){
            break;
        }else max+=temp;
    }while(true);
    return max;
}
int divisible(int n,int a,int b){
    int c1=n/a;
    int c2=n/b;
    int c3=n/lcm(a,b) ;
    return c1+c2-c3;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<divisible(n,a,b)<<endl;
}