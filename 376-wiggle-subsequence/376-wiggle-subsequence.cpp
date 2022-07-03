class Solution {
public:
    
    int getMaxLen(vector<int> &nums, int n, int prev, int cur, 
                  int flag, vector<vector<vector<int>>> &dp) {
        if(cur == n) return 0;
        if(dp[prev][cur][flag] != -1) return dp[prev][cur][flag];
        int val = 0;
        if(flag == 0 || flag == 1) {
            if(nums[cur] - nums[prev] > 0) {
                int newVal = 1 + getMaxLen(nums, n, cur, cur + 1, 2, dp);
                val = max(val, newVal);
            }
        }
        if(flag == 0 || flag == 2) {
            if(nums[cur] - nums[prev] < 0) {
                int newVal = 1 + getMaxLen(nums, n, cur, cur + 1, 1, dp);
                val = max(val, newVal);
            }
        }
        val = max(val, getMaxLen(nums, n, prev, cur + 1, flag, dp));
        return dp[prev][cur][flag] = val;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, 
                                       vector<vector<int>> (n, 
                                                            vector<int> (3, -1)));
        return 1 + getMaxLen(nums, n, 0, 1, 0, dp);
    }
};