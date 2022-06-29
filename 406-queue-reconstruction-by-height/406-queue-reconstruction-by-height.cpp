class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<bool> placeFilled(n+1, false);
        
        vector<vector<int>> ans(n);
        for(auto p : people) {
            int num = p[1], cnt=0, i=0;
            for(; i<n; i++) {
                if(placeFilled[i] && ans[i][0] < p[0]) continue;
                if(cnt == num) break;
                cnt++;
            }
            ans[i] = p;
            placeFilled[i] = true;
        }
        return ans;
    }
};