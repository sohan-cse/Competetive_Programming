#include<bits/stdc++.h>
using namespace std;

void pairIndex(vector<int>&arr,vector<int>&copy_arr,int low,int high){
    int num1=arr[low];
    int num2=arr[high];
    int first=(find(copy_arr.begin(),copy_arr.end(),num1)-copy_arr.begin())+1;
    int second=(find(copy_arr.begin(),copy_arr.end(),num2)-copy_arr.begin())+1;
    first<second?cout<<first<<" "<<second<<endl:cout<<second<<"  "<<first<<endl;


}

bool solve(vector<int>&arr,vector<int>&copy_arr,int target){

    int low=0;
    int high=arr.size()-1;

    while(low<high){
        if(arr[low]+arr[high]==target){
           // cout<<low+1<<"  "<<high+1<<endl;
             pairIndex(arr,copy_arr, low, high);
             return true;
        }else if(arr[low]+arr[high]>target){
            high--;
        }else low++;
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&ele:arr){
        cin>>ele;
    }
    
    //cout<<*(arr.end()-1)<<endl;
    vector<int>copy_arr=arr;

    sort(arr.begin(),arr.end());

    int target;
    cin>>target;
    cout<<solve(arr,copy_arr,target)<<endl;
}