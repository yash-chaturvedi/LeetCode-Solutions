class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int size=2; size<=numRows; size++) {
            vector<int> row(size, 1);
            vector<int> prev = ans[size-2];
            for(int i=1; i<size-1; i++) {
                row[i] = prev[i-1] + prev[i];
            }
            ans.push_back(row);
        }
        return ans;
    }
};