class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;
        map<int, vector<int>> valuesAndIndex = {};
        for (size_t i = 0; i < nums.size(); i++) {
            if (valuesAndIndex.find(nums[i]) == valuesAndIndex.end()) {
                valuesAndIndex[nums[i]] = vector<int>{};
            }
            valuesAndIndex[nums[i]].push_back(i);
        }

        for (auto const& element: valuesAndIndex) {
            if (element.second.size() > 1) {
                for (size_t i = 0; i + i < element.second.size(); i++) {
                    if (element.second[i + 1] - element.second[i] <= k ) {
                        return true;
                    }
                }       
            }
        }
        return false;
    }
};