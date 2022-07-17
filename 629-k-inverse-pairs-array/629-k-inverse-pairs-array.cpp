int dp[1001][1001] = { 1 };
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (dp[n][k])
            return dp[n][k];
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
                if (K >= N)
                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
            }
        return dp[n][k];
    }
};

// class Solution {
// public:
//     int kInversePairs(int n, int k) {
//         vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
//         int mod = 1e9+7;
        
//         for(int i=1; i<=n; i++) {
//             for(int j=0; j<=k; j++) {
                
//                 if(j==0) dp[i][j] = 1;
//                 else {
//                     int ways = 0;
//                     for(int l=0; l<=min(j, i-1); l++) {
//                         ways += dp[i-1][j-l];
//                         ways %= mod;
//                     }
//                     dp[i][j] = ways;
//                 }
//             }
//         }
//         return dp[n][k];
//     }
// };

// class Solution {
//     int mod = 1e9+7;
// public:
//     int helper(int n, int k, vector<vector<int>> &dp) {
//         if(n==0) return 0;
//         if(k==0) return 1;
//         if(dp[n][k] != -1) return dp[n][k];
        
//         int ways = 0;
//         for(int i=0; i<=min(k, n-1); i++) {
//             ways += helper(n-1, k-i, dp);
//             ways %= mod;
//         }
//         return dp[n][k] = ways;
//     }
    
//     int kInversePairs(int n, int k) {
//         vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
//         return helper(n, k, dp);
//     }
// };