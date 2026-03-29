#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) != hashMap.end()) {
                hashMap.find(nums[i])->second++;
            } else {
                hashMap.insert({nums[i], 1});
            }
        }
        int bestVal = 0;
        int bestKey = 0;
        for(const auto&[key, val] : hashMap) {
            if (val > bestVal) {
                bestVal = val;
                bestKey = key;
            }
        }
        return bestKey;
    }
};