class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> waiting(26);
        int ans = 0;
        
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            int pos = str[0] - 'a';
            waiting[pos].push_back(i);
        }
        
        for(char c : s) {
            
            int idx = c - 'a';
            auto curWaiting = waiting[idx];
            waiting[idx].clear();
            
            for(int i : curWaiting) {
                string str = words[i];
                str.erase(str.begin());
                words[i] = str;
                if(str.empty()) ans++;
                else {
                    waiting[str[0] - 'a'].push_back(i);
                }
            }
        }
        
        return ans;
    }
};