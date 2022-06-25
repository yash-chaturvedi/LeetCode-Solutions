class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0, revCnt = 0;
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(i > 0 && nums[i-1] > nums[i+1]) {
                    nums[i+1] = nums[i];
                }
                else {
                    nums[i] = nums[i+1];
                }
                cnt++;
            }
        }
        return cnt < 2;
    }
};