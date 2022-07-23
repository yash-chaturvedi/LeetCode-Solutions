class Solution {
    int BIT[20001]; 
public:
    
    int getSum(int x) {
        int sum = 0;
        for(int i=x; i>0; i-=(i & -i)) {
            sum += BIT[i];
        }
        return sum;
    }
    
    void insert(int x) {
        for(int i=x; i<20001; i+=(i & -i)) {
            BIT[i] += 1;
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        memset(BIT, 0, sizeof BIT);
        int n = nums.size();
        int k = *min_element(nums.begin(), nums.end()) - 1;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--) {
            ans[i] = getSum(nums[i] - k - 1);
            insert(nums[i] - k);
        }
        return ans;
    }
};

// class Solution {
// public:
//     void mergeSort(vector<pair<int, int>> &v, int l, int r, vector<int> &ans) {
//         if(l >= r) return;
        
//         int mid = l + (r-l)/2;
//         mergeSort(v, l, mid, ans);
//         mergeSort(v, mid+1, r, ans);
//         // merge(v, l, mid, r, ans);
//         // Calling extra method was giving tle
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
    
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 0);
//         vector<pair<int, int>> v;
        
//         for(int i=0; i<n; i++) {
//             v.push_back({nums[i], i});
//         }
//         mergeSort(v, 0, n-1, ans);
//         return ans;
//     }
// };