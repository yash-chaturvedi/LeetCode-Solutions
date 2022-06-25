class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        
        if(target.size() == 1) return target[0] == 1;
        
        for(int e : target) {
            pq.push(e);
            sum += e;
        }
        
        while(pq.top() != 1) {
            int maxE = pq.top();
            pq.pop();
            sum -= maxE;
            if(sum > maxE) return false;
            int newE = maxE % sum;
            if(sum != 1 && newE == 0) return false;
            pq.push(newE);
            sum += newE;
        }
        return true;
    }
};