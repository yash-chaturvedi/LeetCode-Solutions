class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        deque<int> q;
        
        score[0] = nums[0];
        q.push_back(0);
        
        for(int i=1; i<n; i++) {
            while(q.front() < i-k) q.pop_front();
            score[i] = nums[i] + score[q.front()];
            while(!q.empty() && score[q.back()] <= score[i]) q.pop_back();
            q.push_back(i);
        }
        return score[n-1];
    }
};

// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<pair<int, int>> pq;
//         vector<int> score(n);
//         score[0] = nums[0];
//         pq.push({nums[0], 0});
        
//         for(int i=1; i<n; i++) {
//             while(!pq.empty() && pq.top().second < i-k) pq.pop();
//             score[i] = pq.top().first + nums[i];
//             pq.push({score[i], i});
//         }
//         return score[n-1];
//     }
// };

// class Solution {
// public:
//     int helper(vector<int>& nums, int k, int i, vector<int> &dp) {
//         if(i == 0) return nums[i];
//         if(dp[i] != -1) return dp[i];
        
//         int cost = INT_MIN;
//         for(int j=i-1; j>=max(0, i-k); j--) {
//             cost = max(cost, helper(nums, k, j, dp));
//         }
//         return dp[i] = cost + nums[i];
//     }
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         return helper(nums, k, n-1, dp);
//     }
// };