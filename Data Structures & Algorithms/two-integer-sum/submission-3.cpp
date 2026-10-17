class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t>mp;
        vector<int>result;
        int diff = 0;
        for(int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            if(mp.contains(diff)) {
                result.push_back(mp.find(diff)->second);
                result.push_back(i);
                return result;
            }
            mp.insert({nums[i], i});
        }
        return result;
    }
};
