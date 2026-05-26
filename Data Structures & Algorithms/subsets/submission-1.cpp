#include <vector>
using namespace std;

class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int> currentSubset, vector<vector<int>>&result, int position) {
        if (position == nums.size()) {
            result.emplace_back(currentSubset);
            return ;
        }
        
        getSubsets(nums, currentSubset, result, position + 1);
        currentSubset.emplace_back(nums[position]);
        getSubsets(nums, currentSubset, result, position + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        getSubsets(nums, {},result, 0);
        
        return result;
    }
};