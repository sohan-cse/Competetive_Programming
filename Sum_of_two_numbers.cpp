#include<bits/stdc++.h>
using namespace std;

vector<int>twoSum(vector<int>&nums,int target){
    vector<int>copy_nums=nums;
    vector<int>result;
    //while(1)cout<<"error";
        sort(copy_nums.begin(),copy_nums.end());
        int p=0;
        int q=copy_nums.size()-1;
        int ele1=-1,ele2=-1;
        while(p<q){
            if(copy_nums[p]+copy_nums[q]==target){
                ele1=copy_nums[p];
                ele2=copy_nums[q];
                break;
            }else if(copy_nums[p]+copy_nums[q]>target){
                q--;
            }else{
                p++;
            }
        }
        bool ele1found=false;
        bool ele2found=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1 && !ele1found){
                result.push_back(i);
                ele1found=true;
            }else if(nums[i]==ele2 && !ele2found){
                result.push_back(i);
                ele2found=true;
            }
            if(result.size()==2)break;
        }
    return result;       
        
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &ele:arr){
        cin>>ele;
    }
    int target;
    cin>>target;
    vector<int>idx=twoSum(arr,target);
    cout<<idx[0]<<idx[1]<<endl;
}