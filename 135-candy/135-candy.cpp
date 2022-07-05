class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        if(n < 2) return n;
        
        int ans = 1, up = 0, down = 0, peak = 0;
        
        for(int i=1; i<n; i++) {
            int slope = ratings[i] - ratings[i-1];
            if(slope > 0) {
                down = 0;
                peak = ++up;
                ans += 1 + up;
            }
            else if(slope == 0) {
                up = down = peak = 0;
                ans += 1;
            }
            else {
                up = 0;
                ans += ++down;
                if(down > peak) ans++;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> candies(n, 1);
//         for(int i=1; i<n; i++) {
//             if(ratings[i] > ratings[i-1]) {
//                 candies[i] = candies[i-1] + 1;
//             }
//         }
//         for(int i=n-2; i>=0; i--) {
//             if(ratings[i] > ratings[i+1]) {
//                 candies[i] = max(candies[i], candies[i+1] + 1);
//             }
//         }
//         int ans = 0;
//         for(int i=0; i<n; i++) {
//             ans += candies[i];
//         }
//         return ans;
//     }
// };