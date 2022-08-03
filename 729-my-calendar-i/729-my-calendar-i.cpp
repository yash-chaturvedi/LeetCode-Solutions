class MyCalendar {
    map<int, int> mp;
public:
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        if(it != mp.end() && (*it).second < end) return false;
        mp[end] = start;
        return true;
    }
};

// class MyCalendar {
//     vector<pair<int, int>> v;
// public:
//     MyCalendar() {
//         v.clear();
//     }
    
//     bool book(int start, int end) {
//         for(auto p : v) {
//             if((p.first < end && p.second > start) || (p.first == end && p.second == start)) {
//                 return false;
//             }
//         }
//         v.push_back({start, end});
//         return true;
//     }
// };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */