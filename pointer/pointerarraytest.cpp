#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int arr[]={1,2,3,4,5};
    // cout<<arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<arr[0]<<endl;
    // cout<<*arr<<endl;
    // cout<<*(arr+1)<<endl;
    int n=sizeof(arr)/sizeof(arr[0]);
    int *ptr=arr;

    for(int i=0;i<n;++i)
    {
        cout<<&arr[i]<<endl;
        cout<<(arr+i)<<endl;
        cout<<arr[i]<<endl;
        cout<<*(arr+i)<<endl;
    }



return 0;
}