#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int singleNumber(vector<int>& nums) {

        int ans=0;
        for(auto&ele:nums){
            ans=ans^ele;
        }
        return ans;
    }

};

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(auto&ele:nums){
        cin>>ele;
    }
    Solution sol;
    int ans=sol.singleNumber(nums);
    cout<<ans;

    return 0;
}