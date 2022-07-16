class Solution {
    int mod=1e9+7;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, -1, 0, 1};
    int dp[50][50][51];
public:
    int helper(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow < 0 || startRow >=m || startColumn < 0 || startColumn >= n) {
            return 1;
        }
        if(maxMove == 0) {
            return 0;
        }
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        int paths = 0;
        for(int i=0; i<4; i++) {
            int r = startRow + dr[i];
            int c = startColumn + dc[i];
            paths += helper(m, n, maxMove-1, r, c);
            paths %= mod;
        }
        return dp[startRow][startColumn][maxMove] = paths;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        return helper(m, n, maxMove, startRow, startColumn);
    }
};