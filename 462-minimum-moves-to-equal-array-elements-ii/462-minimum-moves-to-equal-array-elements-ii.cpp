class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int med = nums[n/2];
        for(int e : nums) {
            ans += abs(e - med);
        }
        return ans;
    }
};