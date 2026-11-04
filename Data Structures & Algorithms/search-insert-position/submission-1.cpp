class Solution {
public:
    
    int twoElements(vector<int>& nums, int left, int right, int target) {
        if (nums[left] >= target) {
            if (target == nums[left] || left == 0)
                return left;
            return left - 1;
        }
        else if (target == nums[right] || (nums[left] < target && target < nums[right])) {
            return right;
        } else {
            return 1 + right;
        }
    }

    int halvesSearch(vector<int>& nums, int target, int left, int right) {
        int mid = ((right - left) / 2) + left;
        if(nums[mid] == target)
            return mid;
        if(right - left <= 1)
            return twoElements(nums, left, right, target);
        if(target > nums[mid])
            return halvesSearch(nums, target, mid, right);
        else
            return halvesSearch(nums, target, left, mid);
    }
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        return halvesSearch(nums, target, 0, nums.size() - 1);
    }
};