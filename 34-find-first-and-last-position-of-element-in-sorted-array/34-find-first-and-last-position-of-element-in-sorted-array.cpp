class Solution {
public:
    int find(vector<int> &nums, int target, bool searchLeft) {
        int n = nums.size();
        int lo = 0, hi = n-1, idx = -1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] < target) {
                lo = mid+1;
            }
            else if(nums[mid] > target) {
                hi = mid-1;
            }
            else {
                idx = mid;
                if(searchLeft) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        return idx;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = find(nums, target, true);
        int r = find(nums, target, false);
        return {l, r};
    }
};