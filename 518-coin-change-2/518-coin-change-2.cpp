class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=amount; j++) {
                if(j==0) dp[j] = 1;
                else if(i > 0 && j >0) {
                    if(coins[i-1] <= j) {
                        dp[j] = dp[j] + dp[j - coins[i-1]];
                    }
                }
            }
        }
        return dp[amount];
    }
};