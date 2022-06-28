class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(), ans = 0;
        vector<int> charFreq(26, 0);
        
        for(char c : s) {
            charFreq[c - 'a']++;
        }
        
        sort(charFreq.begin(), charFreq.end());
        
        for(int i=24; i>=0; i--) {
            int prevFreq = charFreq[i];
            if(charFreq[i] >= charFreq[i+1]) {
                charFreq[i] = max(0, charFreq[i+1] - 1);
            }
            ans += prevFreq - charFreq[i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minDeletions(string s) {
//         int n = s.size(), ans = 0;
//         vector<int> freq(26, 0);
//         vector<bool> freqUsed(n+1, false);
        
//         for(char c : s) {
//             freq[c - 'a']++;
//         }
        
//         for(int i=0; i<26; i++) {
//             if(freq[i] > 0) {
//                 int cnt = 0;
//                 while(freq[i] > 0 && freqUsed[freq[i]]) {
//                     cnt++;
//                     freq[i]--;
//                 }
//                 if(freq[i] >= 0) freqUsed[freq[i]] = true;
//                 ans += cnt;
//             }
//         }
//         return ans;
//     }
// };