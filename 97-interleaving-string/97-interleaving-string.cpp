class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        
        if(n+m != l) return false;

        if(s1.empty()) {
            return s2 == s3;
        }
        if(s2.empty()) {
            return s1 == s3;
        }
        vector<vector<bool>> dp (n+1, vector<bool> (m+1, false));
        
        for(int i=n; i>=0; i--) {
            for(int j=m; j>=0; j--) {
                if(i+j == n+m) dp[i][j] = true;
                else {
                    bool res1 = false, res2 = false;
                    if(i<n && s1[i] == s3[i+j]) res1 = dp[i+1][j];
                    if(j<m && s2[j] == s3[i+j]) res2 = dp[i][j+1];
                    dp[i][j] = res1 || res2;
                }
            }
        }
        return dp[0][0];
    }
};

// class Solution {
// public:
//     bool helper(string &s1, string &s2, string &s3, 
//                 int n, int m, int i, int j, vector<vector<int>> &dp) {
        
//         if(i+j == n+m) return true;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         bool res1 = false, res2 = false;
        
//         if(i<n && s1[i] == s3[i+j]) res1 = helper(s1, s2, s3, n, m, i+1, j, dp);
        
//         if(j<m && s2[j] == s3[i+j]) res2 = helper(s1, s2, s3, n, m, i, j+1, dp);
        
//         return dp[i][j] = res1 || res2;
//     }
    
//     bool isInterleave(string s1, string s2, string s3) {
//         int n = s1.size(), m = s2.size(), l = s3.size();
        
//         if(n+m != l) return false;

//         if(s1.empty()) {
//             return s2 == s3;
//         }
//         if(s2.empty()) {
//             return s1 == s3;
//         }
//         vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
//         return helper(s1, s2, s3, n, m, 0, 0, dp);
//     }
// };