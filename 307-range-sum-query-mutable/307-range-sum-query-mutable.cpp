class NumArray {
    vector<int> BIT;
    vector<int> arr;
    int sum(int i) {
        int s = 0;
        for(; i>0; i -= (i&-i)) {
            s += BIT[i];
        }
        return s;
    }
    
    void updateBIT(int i, int v) {
        for(; i<BIT.size(); i += (i&-i)) {
            BIT[i] += v;
        }
    }
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        BIT = vector<int> (n+1, 0);
        for(int i=0; i<n; i++) {
            updateBIT(i+1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        updateBIT(index+1, val - arr[index]);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */