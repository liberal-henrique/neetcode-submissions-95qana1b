class Solution {
public:
int getSubsetXORSum(vector<int>& nums) {
        int result = 0;
        
        if (nums.size() == 0)
            return result;
        if (nums.size() == 1)
            return nums[0];
        for (size_t i = 0; i + 1 <= nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }

    void getSubsets(vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>&result, int position, int & xorSum) {
        if (position == nums.size()) {
            result.emplace_back(currentSubset);
            xorSum += getSubsetXORSum(currentSubset);
            return ;
        }
        
        getSubsets(nums, currentSubset, result, position + 1, xorSum);
        currentSubset.push_back(nums[position]);
        getSubsets(nums, currentSubset, result, position + 1, xorSum);
        
    }

    int subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        int xorSumResult = 0;
        
        getSubsets(nums, currentSubset,result, 0, xorSumResult);
        
        return xorSumResult;
    }
    int subsetXORSum(vector<int>& nums) {
        return subsets(nums);
    }
};