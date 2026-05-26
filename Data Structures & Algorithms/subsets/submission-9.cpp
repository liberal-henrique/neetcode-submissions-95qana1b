#include <vector>
using namespace std;

class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>&result, int position) {
        for (int i = position; i < nums.size(); i++) {
            currentSubset.push_back(nums[i]);
            result.push_back(currentSubset);
            getSubsets(nums, currentSubset, result, i + 1);
            currentSubset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result {{}};
        vector<int> tmp;
        getSubsets(nums, tmp,result, 0);
        
        return result;
    }
};