class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> totalCharCnt(26, 0);
        for(string s : words2) {
            vector<int> temp(26, 0);
            for(char c : s) {
                temp[c - 'a']++;
            }
            
            for(int i=0; i<26; i++) {
                totalCharCnt[i] = max(totalCharCnt[i], temp[i]);
            }
        }
        
        int n = words1.size();
        vector<vector<int>> wordCharCnt(n, vector<int> (26, 0));
        vector<string> ans;
        
        for(int i=0; i<n; i++) {
            for(char c : words1[i]) {
                wordCharCnt[i][c - 'a']++;
            }
            bool isUniversal = true;
            for(int j=0; j<26; j++) {
                if(wordCharCnt[i][j] < totalCharCnt[j]) {
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) ans.push_back(words1[i]);
        }
        return ans;
    }
};