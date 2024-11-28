#include<iostream>
using namespace std;
class Solution{
    public:
    int sqrt(int x){
        if(x==0){
            return 0;
        }

        int low=0;
        int high=x;
        int result=0;
        while (low<=high){
            int mid=low+(high-low)/2;
            long long square=(long long )mid*mid;
            if(square==x){
                return mid;
            }else if(square<x){
                low=mid+1;
                result=mid;
            }else{
                high=mid-1;    
            }
        }
        return result;
    }  
};


int main(){
    int x;
    cin>>x;
    Solution solution;
    int result=solution.sqrt(x);
    cout<<result<<endl;
    return 0;
}