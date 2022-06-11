class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        for(int i : nums) sum += i;
        
        if(sum < x) return -1;
        if(sum == x) return n;
        
        int target = sum - x, i = 0, curSum = 0, ans = INT_MAX;
        for(int j=0; j<n; j++) {
            curSum += nums[j];
            while(curSum > target) {
                curSum -= nums[i];
                i++;
            }
            if(curSum == target) ans = min(ans, (n - (j - i + 1)));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};