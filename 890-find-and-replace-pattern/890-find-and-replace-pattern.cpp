class Solution {
public:
    bool matches(string &s, string &p) {
        int n = s.size(), m = p.size();
        
        if(n != m) return false;
        
        unordered_map<char, char> mp1, mp2;
        
        for(int i=0; i<n; i++) {
            bool sCharFound = mp1.find(s[i]) != mp1.end();
            bool pCharFound = mp2.find(p[i]) != mp2.end();
            
            if(sCharFound && pCharFound) {
                if(mp1[s[i]] != p[i] || mp2[p[i]] != s[i]) return false;
            }
            else if(sCharFound) {
                return false;
            }
            else if(pCharFound) {
                return false;
            }
            else {
                mp1[s[i]] = p[i];
                mp2[p[i]] = s[i];
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string s : words) {
            if(matches(s, pattern)) ans.push_back(s);
        }
        return ans;
    }
};