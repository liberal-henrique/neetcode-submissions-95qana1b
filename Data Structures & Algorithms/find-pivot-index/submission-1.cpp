class Solution {
public:

    int getIndexToEnd(vector<int>& nums, int index) {
        int result = 0;
        for(; index < nums.size(); index++)
            result += nums[index];
        return result;
    }

    int getBeginningToIndex(vector<int>& nums, int index) {
        int result = 0;
        for(int i = 0; i < index; i++)
            result += nums[i];
        return result;
    }

    int pivotIndex(vector<int>& nums) {
        int pivotIndex = 0;
        int left = 0; 
        int right = 0;
        int totalSum = getIndexToEnd(nums, 0);
        for(; pivotIndex < nums.size(); pivotIndex++) {
            right = getIndexToEnd(nums, (pivotIndex + 1));
            left = getBeginningToIndex(nums, pivotIndex);
            if (right == left)
                return pivotIndex;
        }  
        return -1;
    }
};