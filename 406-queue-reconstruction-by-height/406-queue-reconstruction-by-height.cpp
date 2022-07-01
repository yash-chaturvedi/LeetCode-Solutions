class Solution {
    vector<int> BIT;
    int n;
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        BIT = vector<int> (n+1, 0);
        sort(people.begin(), people.end(), compare);
        
        for(int i=1; i<=n; i++) {
            update(i, 1);
        }
        
        vector<vector<int>> ans(n);
        for(auto p : people) {
            int i = getIdx(p[1]+1);
            ans[i-1] = p;
            update(i, -1);
        }
        return ans;
    }
    
    static bool compare(vector<int> &v1, vector<int> &v2) {
        if(v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] > v2[1];
    }
    
    void update(int i, int x) {
        for(; i <= n; i += (i & -i)) {
            BIT[i] += x;
        }
    }
    
    int getIdx(int val) {
        int lo=1, hi=n;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int midVal = sum(mid);
            if(midVal >= val) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
    
    int sum(int i) {
        int s = 0;
        for(; i>0; i -= (i & -i)) {
            s += BIT[i];
        }
        return s;
    }
};



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

// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         int n = people.size();
//         sort(people.begin(), people.end());
//         vector<bool> placeFilled(n, false);
        
//         vector<vector<int>> ans(n);
//         for(auto p : people) {
//             int cnt=0, i=0;
//             for(; i<n; i++) {
//                 if(placeFilled[i] && ans[i][0] < p[0]) continue;
//                 if(cnt == p[1]) break;
//                 cnt++;
//             }
//             ans[i] = p;
//             placeFilled[i] = true;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     static bool compare(vector<int> &v1, vector<int> &v2) {
//         if(v1[0] != v2[0]) return v1[0] > v2[0];
//         return v1[1] < v2[1];
//     }
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         sort(people.begin(), people.end(), compare);
//         vector<vector<int>> res;
//         for(auto p : people) {
//             res.insert(res.begin() + p[1], p);
//         }
//         return res;
//     }
// };