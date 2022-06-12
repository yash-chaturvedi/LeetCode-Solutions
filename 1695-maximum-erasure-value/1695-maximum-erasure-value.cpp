class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size(), i = 0, j = 0, maxSum = 0, curSum = 0;
        unordered_map<int, int> mp;
        
        while(i < n) {
            if(mp[a[i]] == 0) {
                curSum += a[i];
                mp[a[i]]++;
                i++;
            }
            else {
                curSum -= a[j];
                mp[a[j]]--;
                j++;
            }
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};