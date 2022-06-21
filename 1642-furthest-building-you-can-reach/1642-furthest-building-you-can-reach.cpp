class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n-1; i++) {
            int hDiff = heights[i+1] - heights[i];
            if(hDiff <= 0) continue;
            pq.push(hDiff);
            if(pq.size() > ladders) {
                int minDiff = pq.top();
                pq.pop();
                bricks -= minDiff;
                if(bricks < 0) return i;
            }
        }
        return n-1;
    }
};