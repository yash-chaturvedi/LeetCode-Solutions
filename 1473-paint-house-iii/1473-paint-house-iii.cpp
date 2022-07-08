class Solution {
    int dp[100][21][101];
public:
    int helper(vector<int>& houses, vector<vector<int>>& cost, 
                int m, int n, int target, int i, int prevCol, int neighbourhoods) {
        
        if(i==m) {
            if(neighbourhoods == target) return 0;
            else return 1000001;
        }
        if(dp[i][prevCol][neighbourhoods] != -1) {
            return dp[i][prevCol][neighbourhoods];
        }
        
        int minCost = 1000001;
        if(houses[i] == 0) {
            for(int j=0; j<n; j++) {
                int newNeighbourhoodCnt = neighbourhoods + (j+1 != prevCol);
                int curCost = cost[i][j] + helper(houses, cost, m, n, 
                                     target, i+1, j+1, newNeighbourhoodCnt);
                minCost = min(minCost, curCost);
            }
        }
        else {
            int newNeighbourhoodCnt = neighbourhoods + (houses[i] != prevCol);
            minCost = helper(houses, cost, m, n, target, i+1, 
                             houses[i], newNeighbourhoodCnt);
        }
        return dp[i][prevCol][neighbourhoods] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, 
                int m, int n, int target) {
        memset(dp, -1, sizeof dp);
        int ans = helper(houses, cost, m, n, target, 0, 0, 0);
        return ans == 1000001 ? -1 : ans;
    }
};