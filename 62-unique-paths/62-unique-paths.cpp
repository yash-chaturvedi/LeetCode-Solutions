class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N = m+n-2, R = m-1;
        long long ans = 1ll;
        
        for(int i=1; i<=R; i++) {
            ans *= N - (R - i);
            ans /= i;
        }
        
        return ans;
    }
};