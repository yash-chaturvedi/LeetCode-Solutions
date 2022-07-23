class Solution {
public:
    
//     void merge(vector<pair<int, int>> &v, int l, int mid, int r, vector<int> &ans) {
//         int i = l, j = mid+1;
//         vector<pair<int, int>> temp;
        
//         while(i <= mid && j <= r) {
//             if(v[j] < v[i]) {
//                 temp.push_back(v[j]);
//                 j++;
//             }
//             else {
//                 ans[v[i].second] += j - (mid+1);
//                 temp.push_back(v[i]);
//                 i++;
//             }
//         }
        
//         while(i <= mid) {
//             ans[v[i].second] += j - (mid+1);
//             temp.push_back(v[i]);
//             i++;
//         }
        
//         while(j <= r) {
//             temp.push_back(v[j]);
//             j++;
//         }
        
//         for(int it=l; it<=r; it++) {
//             v[it] = temp[it - l];
//         }
//     }
    
    void mergeSort(vector<pair<int, int>> &v, int l, int r, vector<int> &ans) {
        if(l >= r) return;
        
        int mid = l + (r-l)/2;
        mergeSort(v, l, mid, ans);
        mergeSort(v, mid+1, r, ans);
        // merge(v, l, mid, r, ans);
        
        int i = l, j = mid+1;
        vector<pair<int, int>> temp;
        
        while(i <= mid && j <= r) {
            if(v[j] < v[i]) {
                temp.push_back(v[j]);
                j++;
            }
            else {
                ans[v[i].second] += j - (mid+1);
                temp.push_back(v[i]);
                i++;
            }
        }
        
        while(i <= mid) {
            ans[v[i].second] += j - (mid+1);
            temp.push_back(v[i]);
            i++;
        }
        
        while(j <= r) {
            temp.push_back(v[j]);
            j++;
        }
        
        for(int it=l; it<=r; it++) {
            v[it] = temp[it - l];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) {
            v.push_back({nums[i], i});
        }
        mergeSort(v, 0, n-1, ans);
        return ans;
    }
};