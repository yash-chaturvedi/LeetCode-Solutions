class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        int maxLen = 0, start = -1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int l=1; l<=n; l++) {
            for(int i=0; i+l-1<n; i++) {
                int j = i+l-1;
                if(l == 1) dp[i][j] = 1;
                else if(l == 2) dp[i][j] = s[i] == s[j] ? 1 : 0;
                else {
                    if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                    else dp[i][j] = 0;
                }
                if(dp[i][j] == 1 && l > maxLen) {
                    maxLen = l;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};