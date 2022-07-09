class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> dp(n+1);
        priority_queue<pair<int,int>> q;
        
        dp[1] = nums[0];
        q.push({dp[1],1});
        
        for(int i=2;i<=n;i++){
            int pos = q.top().second;
            while(pos+k<i){
                q.pop();
                pos = q.top().second;
            }
            int mx = q.top().first;
        
            dp[i] = nums[i-1] + mx;
            q.push({dp[i],i});
        }
        return dp[n];
        
    }
};