#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int singleNumber(vector<int>& nums){
        unordered_map<int,int>hashTable;
        for(auto num:nums){
            hashTable[num]++;
        }
        int result;
        for(auto ele:hashTable){
            if(ele.second==1){
                result=ele.first;
                break;
            }
        }

        return result;
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
    cout<<ans<<endl;

    return 0;
}