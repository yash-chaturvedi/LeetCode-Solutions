class Solution {
public:
    static bool compare(vector<int> &c1, vector<int> &c2) {
        return c1[1] < c2[1];    
    }  
    int scheduleCourse(vector<vector<int>>& courses) {
        int day = 0;
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), compare);
        
        for(auto c : courses) {
            if(day + c[0] <= c[1]) {
                day += c[0];
                pq.push(c[0]);
            }
            else if(!pq.empty() && pq.top() > c[0]){
                day -= pq.top();
                pq.pop();
                pq.push(c[0]);
                day += c[0];
            }
        }
        return pq.size();
    }
};