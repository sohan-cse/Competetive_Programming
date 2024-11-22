#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>&arr,int n){
    int currSum=0;
    int mxSum=INT_MIN;

    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum<0){
            currSum=0;
        }
        mxSum=max(mxSum,currSum);
    }
    
    return mxSum;
}

int main(){
   int n;
   cin>>n;

   vector<int>arr(n);
   for(auto&ele:arr) {
    cin>>ele;
   }

   int nonWrapSum=kadane(arr,n);
   int totalSum=0;

   for(int i=0;i<n;i++){
    totalSum+=arr[i];
    arr[i]=-arr[i];
   }

   int wrapSum=totalSum+kadane(arr,n);
   cout<<max(nonWrapSum,wrapSum)<<endl;

    return 0;
}