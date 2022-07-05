class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i : nums) {
            s.insert(i);
        }
        int ans = 0;
        for(int i : nums) {
            if(s.count(i-1) == 0) {
                int cnt = 0;
                while(s.count(i)) {
                    cnt++;
                    i++;
                }
                ans = max(ans, cnt);
            } 
        }
        return ans;
    }
};