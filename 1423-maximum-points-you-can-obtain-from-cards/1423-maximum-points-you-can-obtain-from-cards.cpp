
class Solution {
    public :
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), lSum = 0;
        for(int i = 0; i < k; ++i){
            lSum += cardPoints[i];
        }
        int ans = lSum;
        for(int rSum = 0, i = 0; i < k; ++i){
            rSum += cardPoints[n-1-i];
            lSum -= cardPoints[k-1-i];
            ans = max(ans,lSum+rSum);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size(), ans = 0;
//         for(int i=1; i<n; i++) {
//             cardPoints[i] += cardPoints[i-1];
//         }
        
//         for(int i=0; i<=k; i++) {
//             int left = i > 0 ? cardPoints[i-1] : 0;
//             int right = k-i > 0 
//                 ? cardPoints[n-1] - ((n-1-(k-i )>= 0) ? cardPoints[n-1-(k-i)] : 0 )
//                 : 0;
//             // cout<<left<<" "<<right<<" "<<cardPoints[n-1]<<" "<<cardPoints[n-1-k-i]<<endl;
//             ans = max(ans, left + right);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
    
//     int helper(int i, int j, vector<int> &cardPoints, int k, vector<vector<vector<int>>> &dp) {
//         if(i > j) return 0;
//         if(k == 0) return 0;
//         if(dp[i][j][k] != -1) return dp[i][j][k];
//         int left = cardPoints[i] + helper(i+1, j, cardPoints, k-1, dp);
//         int right = cardPoints[j] + helper(i, j-1, cardPoints, k-1, dp);
        
//         return dp[i][j][k] = max(left, right);
//     }
    
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n+1, -1)));
//         return helper(0, n-1, cardPoints, k, dp);
//     }
// };