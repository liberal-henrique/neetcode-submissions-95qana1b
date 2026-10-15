class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = i + 1;
        int size = nums.size();
        vector<int> result;
        for(; i < size - 1; i++) {
            j = i + 1;
            for(; j < size; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
