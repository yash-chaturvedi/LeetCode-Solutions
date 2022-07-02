class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, 
                vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int hMax = 0, vMax = 0, mod = 1e9 + 7;
        for(int i=0; i<horizontalCuts.size()-1; i++) {
            hMax = max(hMax, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        
        for(int i=0; i<verticalCuts.size()-1; i++) {
            vMax = max(vMax, verticalCuts[i+1] - verticalCuts[i]);
        }

        return (hMax * 1ll * vMax) % mod;
    }
};