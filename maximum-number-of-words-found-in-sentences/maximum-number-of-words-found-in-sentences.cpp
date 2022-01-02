class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string s : sentences) {
            int cnt = 0;
            istringstream str(s);
            while(str >> s) {
                cnt++;
            }
            if(cnt > ans) {
                ans = cnt;
            }
        }
        return ans;
    }
};