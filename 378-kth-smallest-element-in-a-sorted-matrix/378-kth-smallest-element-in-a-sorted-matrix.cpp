class Solution {
public:
    
    int getNumElementsLessThanOrEqual(vector<vector<int>>& matrix, int x) {
        int n = matrix.size();
        int i = 0, j = n-1, cnt = 0;
        
        while(i<n && j>=0) {
            if(matrix[i][j] <= x) {
                cnt += j+1;
                i++;
            }
            else {
                j--;
            }
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1];
        int ans;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int num = getNumElementsLessThanOrEqual(matrix, mid);
            if(num >= k) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
};