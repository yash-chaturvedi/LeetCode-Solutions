class Solution {
public:
    int minPartitions(string s) {
        
        int maxDig = 0;
        for(int i=0; i<s.size(); i++) {
            int dig = s[i] - '0';
            maxDig = max(maxDig, dig);
        }
        return maxDig;
    }
};