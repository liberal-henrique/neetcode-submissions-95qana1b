class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nZeros = 0;
        int swap = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nZeros++;
            } else {
                if(nZeros > 0) {
                    nums[i - nZeros] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};