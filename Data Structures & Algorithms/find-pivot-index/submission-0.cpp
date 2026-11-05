class Solution {
public:
    pair<int,int> getAdditionLeftAndRight(vector<int>& nums, int index) {
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i < index) {
                left += nums[i];
            } else if (i > index) {
                right += nums[i];
            }
        }
        return {left, right};
    }

    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        pair<int,int> result;
        for(int i = 0; i < size; i++) {
            result = getAdditionLeftAndRight(nums, i);
            if(result.first == result.second)
                return i;
        }
        return -1;
    }
};