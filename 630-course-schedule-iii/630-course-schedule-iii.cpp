class Comparator {
    public :
    bool operator()(vector<int> &c1, vector<int> &c2) {
        return c1[0] < c2[0];    
    }  
};

class Solution {
public:
    static bool compare(vector<int> &c1, vector<int> &c2) {
        return c1[1] < c2[1];    
    }  
    int scheduleCourse(vector<vector<int>>& courses) {
        int day = 0;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        sort(courses.begin(), courses.end(), compare);
        for(auto c : courses) {
            if(day + c[0] <= c[1]) {
                day += c[0];
                pq.push(c);
            }
            else if(!pq.empty()){
                auto t = pq.top();
                if(t[0] > c[0]) {
                    pq.pop();
                    pq.push(c);
                    day -= t[0];
                    day += c[0];
                }
            }
        }
        return pq.size();
    }
};