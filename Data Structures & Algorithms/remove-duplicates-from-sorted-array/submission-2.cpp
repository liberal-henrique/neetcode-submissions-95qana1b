class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)   
            return 1;
        int left = 0;
        int right = 1;
        while(right < size) {
            if(nums[left] == nums[right]) { 
                while(right <= size - 1 && nums[left] == nums[right]) {
                    nums.erase(nums.begin() + left, nums.begin() + right);
                    size--;
                }
            } else {
                left = right;
                right++;
            }
        }
        return nums.size();
    }
};
