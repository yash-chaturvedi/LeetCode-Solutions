// class Solution {
// public:
//     int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
//         int res = 0, m = A.size(), n = A[0].size();
//         for (int i = 0; i < m; i++)
//             for (int j = 1; j < n; j++)
//                 A[i][j] += A[i][j - 1];

//         unordered_map<int, int> counter;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 counter = {{0,1}};
//                 int cur = 0;
//                 for (int k = 0; k < m; k++) {
//                     cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
//                     res += counter.find(cur - target) != counter.end() 
//                                 ? counter[cur - target] 
//                                 : 0;
//                     counter[cur]++;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int helper(vector<int> &temp, int m, int t) {
        int cnt = 0, sum = 0;
        unordered_map<int, int> mp = {{0, 1}};
        
        for(int i=0; i<m; i++) {
            sum += temp[i];
            cnt += mp[sum - t];
            mp[sum]++;
        }
        return cnt;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        
        for(int i=0; i<n; i++) {
            vector<int> temp(m, 0);
            for(int j=i; j<n; j++) {
                
                for(int k=0; k<m; k++) {
                    temp[k] += mat[j][k];
                }
                
                ans += helper(temp, m, t);
            }
        }
        
        return ans;
    }
};