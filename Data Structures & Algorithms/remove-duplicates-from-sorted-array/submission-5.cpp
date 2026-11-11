class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int k = 0;
        int i = 1;
        int sw = 0;
        for(; i < size; i++) {
            if(nums[i] > nums[k]) {
                nums[k + 1] = nums[i];
                k++;
            }
        }
        return k + 1;
    }
};