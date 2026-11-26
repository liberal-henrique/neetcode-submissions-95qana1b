class Solution {
public:

    int getIndexToEnd(vector<int>& nums, int index) {
        int result = 0;
        for(; index < nums.size(); index++)
            result += nums[index];
        return result;
    }

    int pivotIndex(vector<int>& nums) {
        int pivotIndex = 0;
        int left = 0; 
        int right = 0;
        int totalSum = getIndexToEnd(nums, 0);
        for(; pivotIndex < nums.size(); pivotIndex++) {
            printf("pivotIndex -> %i\n", pivotIndex);
            if(pivotIndex > 0)
                left += nums[pivotIndex - 1];
            right += (totalSum - nums[pivotIndex] - left);
            printf("Left -> %i\n", left);
            printf("Right -> %i\n", right);
            if(left == right)
                return pivotIndex;
            right = 0;
        }  
        return -1;
    }
};