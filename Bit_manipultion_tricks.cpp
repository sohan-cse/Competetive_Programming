#include<bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i=7;i>=0;--i){
        cout<<(1&(num>>i));
    }
    cout<<endl;
}
int main(){
    for(int i=0;i<=100;i++){
        printBinary(i);
        if(1&i){
            cout<<"Odd"<<endl;
        }else{
            cout<<"Even"<<endl;
        }
    }

    int n=9;
    //multiplication by 2
    cout<<"n multiplied by 2 :"<<(n<<1)<<endl;
    //division by 2
    cout<<"n divided by 2 :"<<(n>>1)<<endl;

}