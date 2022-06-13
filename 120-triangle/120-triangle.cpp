class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> next(n+1, 0), cur(n+1, 0);
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                cur[j] = a[i][j] + min(next[j], next[j+1]);
            }
            next = cur;
        }
        return cur[0];
    }
};