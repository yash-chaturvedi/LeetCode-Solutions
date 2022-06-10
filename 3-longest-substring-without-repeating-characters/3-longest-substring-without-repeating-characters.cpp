class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        vector<int> cnt(255, 0);
        int i=0,j=0;
        while(j < n) {
            if(cnt[s[j]] == 0) {
                cnt[s[j]]++;
                j++;
            }
            else {
                while(cnt[s[j]]) {
                    cnt[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};