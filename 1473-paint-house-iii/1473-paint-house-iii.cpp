class Solution {
public:
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Initialize memo array
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(target + 1, vector<int>(n, MAX_COST)));
            
        // Initialize for house 0, neighborhoods will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                // If the house has same color, no cost
                memo[0][1][color - 1] = 0;
            } else if (!houses[0]) {
                // If the house is not painted, assign the corresponding cost
                memo[0][1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted, and color is different
                    if (houses[house] && color != houses[house]) {
                        // Cannot be painted with different color
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = min(currCost, memo[house - 1][neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = min(currCost, memo[house - 1][neighborhoods][color - 1]);
                        }
                    }

                    // If the house is already painted cost to paint is 0
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[house][neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, memo[m - 1][target][color - 1]);
        }
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return minCost == MAX_COST ? -1 : minCost;
    }
};

// class Solution {
//     int dp[100][21][101];
// public:
//     int helper(vector<int>& houses, vector<vector<int>>& cost, 
//                 int m, int n, int target, int i, int prevCol, int neighbourhoods) {
        
//         if(i==m) {
//             if(neighbourhoods == target) return 0;
//             else return 1000001;
//         }
//         if(dp[i][prevCol][neighbourhoods] != -1) {
//             return dp[i][prevCol][neighbourhoods];
//         }
        
//         int minCost = 1000001;
//         if(houses[i] == 0) {
//             for(int j=0; j<n; j++) {
//                 int newNeighbourhoodCnt = neighbourhoods + (j+1 != prevCol);
//                 int curCost = cost[i][j] + helper(houses, cost, m, n, 
//                                      target, i+1, j+1, newNeighbourhoodCnt);
//                 minCost = min(minCost, curCost);
//             }
//         }
//         else {
//             int newNeighbourhoodCnt = neighbourhoods + (houses[i] != prevCol);
//             minCost = helper(houses, cost, m, n, target, i+1, 
//                              houses[i], newNeighbourhoodCnt);
//         }
//         return dp[i][prevCol][neighbourhoods] = minCost;
//     }
    
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, 
//                 int m, int n, int target) {
//         memset(dp, -1, sizeof dp);
//         int ans = helper(houses, cost, m, n, target, 0, 0, 0);
//         return ans == 1000001 ? -1 : ans;
//     }
// };