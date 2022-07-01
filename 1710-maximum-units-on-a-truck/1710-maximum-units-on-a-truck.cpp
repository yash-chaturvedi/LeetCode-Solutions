class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        for(auto v : boxTypes) {
            if(v[0] <= truckSize) {
                truckSize -= v[0];
                ans += v[0] * v[1];
            }
            else {
                ans += truckSize * v[1];
                break;
            }
        }
        return ans;
    }
    
    static bool compare(vector<int> &v1, vector<int> &v2) {
        return v1[1] > v2[1];
    }
};