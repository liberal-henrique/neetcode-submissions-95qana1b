class Solution {
public:
    
    int insertionPosition(vector<int>& nums, int left, int right, int target) {
        int position = left + (right - left) / 2;
        if (right - left <= 0) {
            if (target > nums[position])
                position++;
            return position;
        }

        if (nums[position] == target)
            return position;
        
        if (target > nums[position]) {
            return insertionPosition(nums, position + 1, right, target);
        } else {
            return insertionPosition(nums, left, position - 1, target);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        size_t size = nums.size();
        if (size == 0)
            return 0;
        return insertionPosition(nums, 0, size - 1, target);
    }
};