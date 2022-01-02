class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string s : operations) {
            char op = s[1];
            if(op == '+') {
                x++;
            }else{
                x--;
            }
        }
        return x;
    }
};