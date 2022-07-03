class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int prevDiff = nums[1] - nums[0];
        int len = prevDiff == 0 ? 1 : 2;
        for(int i=2; i<n; i++) {
            int curDiff = nums[i] - nums[i-1];
            if((curDiff > 0 && prevDiff <= 0) || (curDiff < 0 && prevDiff >=0)) {
                len++;
                prevDiff = curDiff;
            }
        }
        return len;
    }
};

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n < 2) return n;
//         int up = 1, down = 1;
        
//         for(int i=1; i<n; i++) {
//             if(nums[i] > nums[i-1]) {
//                 up = 1 + down;
//             }
//             else if(nums[i] < nums[i-1]) {
//                 down = 1 + up;
//             }
//         }
//         return max(up, down);
//     }
// };

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n < 2) return n;
//         vector<vector<int>> dp(n+1, vector<int> (2, 0));
//         dp[0][0] = dp[0][1] = 1;
//         for(int i=1; i<n; i++) {
            
//             dp[i][0] = dp[i-1][0];
//             dp[i][1] = dp[i-1][1];
            
//             if(nums[i] > nums[i-1]) {
//                 dp[i][0] = 1 + dp[i-1][1];
//             }
//             else if(nums[i] < nums[i-1]) {
//                 dp[i][1] = 1 + dp[i-1][0];
//             }
//         }
//         return max(dp[n-1][0], dp[n-1][1]);
//     }
// };

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n < 2) return n;
//         // We have two states :
//         // 0 -> cur element is greater than prev
//         // 1 -> cur element is smaller than prev
//         vector<vector<int>> dp(n, vector<int> (2, 0));
//         for(int i=0; i<n; i++) {
//             dp[i][0] = dp[i][1] = 1;
//             for(int j=0; j<i; j++) {
//                 if(nums[i] > nums[j]) {
//                     dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
//                 }
//                 else if(nums[i] < nums[j]) {
//                     dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
//                 }
//             }
//         }
//         return max(dp[n-1][0], dp[n-1][1]);
//     }
// };
