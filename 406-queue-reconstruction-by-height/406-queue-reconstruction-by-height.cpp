
// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         sort(people.begin(), people.end(), cmp);
//         vector<vector<int>> res(people.size(), vector<int>());
//         for(int i = 0; i < people.size(); i++){
//             int cnt, j;
//             for(cnt = 0, j = 0; j < res.size(); j++){ //empty count start from 0
//                 if(res[j].empty()){
//                     if(cnt==people[i][1]) break;
//                     cnt++;
//                 }
//             }
//             res[j]=people[i];
//         }
//         return res;
//     }
//     static bool cmp(vector<int>& p1, vector<int>& p2){
//         if(p1[0]!=p2[0]) return p1[0]<p2[0];
//         else return p1[1]>p2[1];
//     }
// };

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<bool> placeFilled(n, false);
        
        vector<vector<int>> ans(n);
        for(auto p : people) {
            int cnt=0, i=0;
            for(; i<n; i++) {
                if(placeFilled[i] && ans[i][0] < p[0]) continue;
                if(cnt == p[1]) break;
                cnt++;
            }
            ans[i] = p;
            placeFilled[i] = true;
        }
        return ans;
    }
};