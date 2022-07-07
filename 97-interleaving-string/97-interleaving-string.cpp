class Solution {
public:
    
    bool helper(string &s1, string &s2, string &s3, 
                int n, int m, int l, int i, int j, int k, 
                vector<vector<vector<int>>> &dp) {
        
        if(k == l) return true;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        bool res1 = false, res2 = false;
        
        if(i<n && s1[i] == s3[k]) res1 = helper(s1, s2, s3, 
                                                n, m, l, i+1, j, k+1, dp);
        
        if(j<m && s2[j] == s3[k]) res2 = helper(s1, s2, s3, 
                                                n, m, l, i, j+1, k+1, dp);
        
        return dp[i][j][k] = res1 || res2;
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
        vector<vector<vector<int>>> dp
            (n+1, vector<vector<int>> (m+1, vector<int> (l+1, -1)));
        return helper(s1, s2, s3, n, m, l, 0, 0, 0, dp);
    }
};