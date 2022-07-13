class Solution {
public:
    
    bool helper(vector<int> &matchsticks, int n, vector<bool> &used, 
                int oneSideLen, int sidesDone, int curLen, int i) {
        
        if(sidesDone == 4) return true;
        if(curLen == oneSideLen) return helper(matchsticks, n, used, oneSideLen, sidesDone+1, 0, 0);
        if(i==n) return false;
        
        for(; i<n; i++) {
            if(!used[i] && (curLen + matchsticks[i] <= oneSideLen)) {
                used[i] = true;
                if(helper(matchsticks, n, used, oneSideLen, sidesDone, 
                          curLen + matchsticks[i], i+1)) return true;
                used[i] = false;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int k = 0;
        for(int l : matchsticks) k+=l;
        if(k % 4 != 0) return false;
        k /= 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        vector<bool> used(n, false);
        return helper(matchsticks, n, used, k, 0, 0, 0);
    }
};

// class Solution {
// public:
    
//     bool helper(vector<int>& matchsticks, int n, int i, int a, int b, int c, int d, int k) {
//         if(i==n) return (a==b && b==c && c==d && d==k);
        
//         bool case1=false, case2=false, case3=false, case4=false;
        
//         if(a + matchsticks[i] <= k) 
//             case1 = helper(matchsticks, n, i+1, a + matchsticks[i], b, c, d, k);
        
//         if(b + matchsticks[i] <= k) 
//             case2 = helper(matchsticks, n, i+1, a, b + matchsticks[i], c, d, k);
        
//         if(c + matchsticks[i] <= k) 
//             case3 = helper(matchsticks, n, i+1, a, b, c + matchsticks[i], d, k);
        
//         if(d + matchsticks[i] <= k) 
//             case4 = helper(matchsticks, n, i+1, a, b, c, d + matchsticks[i], k);
        
//         return case1 || case2 || case3 || case4;
//     }
    
//     bool makesquare(vector<int>& matchsticks) {
//         int n = matchsticks.size();
//         int k = 0;
//         for(int l : matchsticks) k+=l;
//         if(k % 4 != 0) return false;
//         k /= 4;
//         sort(matchsticks.begin(), matchsticks.end(), greater<>());
//         return helper(matchsticks, n, 0, 0, 0, 0, 0, k);
//     }
// };