class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=n-1, j=2*n-1;
        while(i>=0) {
            nums[j] <<= 10;
            nums[j] |= nums[i];
            j--;
            i--;
        }
        i=0;
        j=n;
        while(i<2*n) {
            nums[i] = (nums[j] & 1023);
            nums[i+1] = (nums[j] >> 10);
            i+=2;
            j+=1;
        }
        return nums;
    }
};