class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(), ans = 0;
        vector<int> freq(26, 0);
        vector<bool> freqUsed(n+1, false);
        
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                int cnt = 0;
                while(freq[i] > 0 && freqUsed[freq[i]]) {
                    cnt++;
                    freq[i]--;
                }
                if(freq[i] >= 0) freqUsed[freq[i]] = true;
                ans += cnt;
            }
        }
        return ans;
    }
};