#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr,int target){
    int low=0;
    int high=arr.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    int target;
    cin>>target;
    cout<<binarySearch(arr,target)<<endl;
}