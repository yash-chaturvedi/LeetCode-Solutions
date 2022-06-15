class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};