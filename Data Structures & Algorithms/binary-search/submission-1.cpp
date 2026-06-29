class Solution {
public:

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int position = left +  ((right - left) / 2);
        
        if (right - left <= 0) {
            if (target == nums[right])
                return (right);
            return -1;
        }

        if (target == nums[position])
            return position;
        if (target > nums[position]) {
            position = left + ((right - left) / 2) + 1;
            return binarySearch(nums, position, right, target);
        }
        else {
            position = left + ((right - left) / 2) - 1;
            return binarySearch(nums, left, position, target);
        } 
    }

    int search(vector<int>& nums, int target) {
        size_t size = nums.size();
        if (size == 0 || (size == 1 && nums[0] != target))
            return -1;
        if (size == 1 && nums[0] == target)
            return 0;
        if (size == 2) {
            if (nums[0] == target)
                return 0;
            else if (nums[1] == target)
                return 1;
            else 
                return -1;
        }

        int position = size/2;
        int middleValue = nums[position];
        if (middleValue == target)
            return position;
        else if (middleValue < target)
            return binarySearch(nums, position, size - 1, target);
        else
            return binarySearch(nums, 0, position, target);
    }
};
