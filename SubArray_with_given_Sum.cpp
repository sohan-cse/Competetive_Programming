#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,give_sum;
    cin>>n>>give_sum;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }

    int i=0,j=0;
    int st=-1,en=-1;
    int sum=0;
    while(j<n && sum+arr[j]<=give_sum){
        sum+=arr[j];
        j++;
    }
    if(sum==give_sum){
        st=i+1;
        en=j;
        cout<<st<<"  "<<en<<endl;
        return 0;
    }
    while(j<n){
        sum+=arr[j];
        while(sum>give_sum){
            sum-=arr[i];
            i++;
        }
        if(sum==give_sum){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }
    cout<<st<<"  "<<en<<endl;
}
