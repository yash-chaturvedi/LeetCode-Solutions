class Solution {
public:
    bool helper(string &s1, string &s2, string &s3, 
                int n, int m, int i, int j, vector<vector<int>> &dp) {
        
        if(i+j == n+m) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool res1 = false, res2 = false;
        
        if(i<n && s1[i] == s3[i+j]) res1 = helper(s1, s2, s3, n, m, i+1, j, dp);
        
        if(j<m && s2[j] == s3[i+j]) res2 = helper(s1, s2, s3, n, m, i, j+1, dp);
        
        return dp[i][j] = res1 || res2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        
        if(n+m != l) return false;

        if(s1.empty()) {
            return s2 == s3;
        }
        if(s2.empty()) {
            return s1 == s3;
        }
        vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
        return helper(s1, s2, s3, n, m, 0, 0, dp);
    }
};