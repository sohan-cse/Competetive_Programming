#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;  
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(auto&ele:nums){
        cin>>ele;
    }
    int target;
    cin>>target;
    Solution solution;
    int ans=solution.searchInsert(nums,target);
    cout<<ans<<endl;

    return 0;
}
