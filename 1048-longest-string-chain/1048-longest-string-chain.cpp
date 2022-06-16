class Solution {
    
    string deleteCharAt(string &word, int i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i+1);
        return prefix + suffix;
    }
    
    int helper(unordered_map<string, int> &dp, 
               unordered_set<string> &possibleWords, string word) {
        int n = word.size();
        if(n == 0) return 0;
        if(dp[word]) return dp[word];
        int len = 0;
        for(int i=0; i<n; i++) {
            string next = deleteCharAt(word, i);
            if(possibleWords.count(next) != 0) {
                len = max(len, helper(dp, possibleWords, next));
            }
        }
        return dp[word] = len + 1;
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        unordered_set<string> possibleWords(words.begin(), words.end());
        
        int ans = 1;
        for(string w : words) {
            ans = max(ans, helper(dp, possibleWords, w));
        }
        return ans;
    }
};