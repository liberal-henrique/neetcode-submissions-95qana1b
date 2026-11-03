class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;
        int right = 1;
        int size = nums.size();
        while(right < size) {
            if(nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};
